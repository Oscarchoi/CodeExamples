#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define NAME_POSIX_SEM "/my_sem"
const int max_child = 30;
sem_t* p_psem;

int process_child(int);

int main(int argc, char* argv[]) {
  int i, n_count, sem_value, status;
  if (argc != 2) {
    printf("%s [counter]\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  n_count = atoi(argv[1]);  // 생성할 세마포어 카운터
  p_psem = sem_open(NAME_POSIX_SEM, O_CREAT | O_EXCL, 0600, n_count);

  if (p_psem == SEM_FAILED) {
    if (errno != EEXIST) {
      fprintf(stderr, "FAIL: sem_open()\n");
    }
    p_psem = sem_open(NAME_POSIX_SEM, 0);
    printf("Attach to an existed sem\n");

  } else {
    printf("[%d] Create new sem\n", getpid());
  }

  sem_getvalue(p_psem, &sem_value);
  printf("[%d] sem_getvalue = %d\n", getpid(), sem_value);

  // struct timespec ts_timeout;
  // ts_timeout.tv_sec = time(NULL) + 10;  // add 10 sec to current unix time
  // ts_timeout.tv_nsec = 0;
  // if (sem_timedwait(p_psem, &ts_timeout) == -1) {
  //   if (errno == ETIMEDOUT) {
  //     printf("sem_timedwait() timeout\n");
  //   } else {
  //     printf("sem_timedwait() error\n");
  //   }
  // }

  for (i = 0; i < max_child; i++) {
    printf("[%d] iteration(%d) : Atomically decrease\n", getpid(), i);
    sem_wait(p_psem);
    switch (fork()) {
      case 0:  // child
        process_child(i);
        sem_post(p_psem);  // atomically increase
        exit(EXIT_SUCCESS);
      case -1:  // error
        fprintf(stderr, "FAIL: fork() [%s:%d]\n", __FUNCTION__, __LINE__);
        exit(EXIT_FAILURE);
      default:  // parent
        break;
    }
    usleep(10000);
  }

  for (i = 0; i < max_child; i++) {
    pid_t pid_child;
    if ((pid_child = waitpid(-1, &status, 0)) == -1) {
      fprintf(stderr, "FAIL: waitpid()\n");
      exit(EXIT_FAILURE);
    }
  }

  sem_getvalue(p_psem, &sem_value);
  printf("[%d] sem_getvalue = %d\n", getpid(), sem_value);
  if (sem_unlink(NAME_POSIX_SEM) == -1) {  // remote sem
    fprintf(stderr, "FAIL: sem_unlink()\n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}

int process_child(int i) {
  if (i == 11) abort();
  printf("\t[Child:%d] sleep(2)\n", i);
  sleep(2);
  return 0;
}
