#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <semaphore.h>

#define SHM_SEGMENT_SIZE 65536
#define SHM_SEGMENT_NAME "/demo-shm"
#define SEMA_NAME "/demo-sem"

static sem_t *demo_sem;

/* 
 * 공유 메모리 세그먼트가 이미 존재하지 않으면 만든다.
 * 세그먼트의 포인터를 리턴한다. 에러 발생시 NULL을 리턴한다.
 */

static void *get_shared_memory(void){
  int shm_fd;
  struct shared_data *shm_p;
  /* 공유 메모리 세그먼트 생성 시도 */
  shm_fd = shm_open(SHM_SEGMENT_NAME, O_CREAT | O_EXCL | O_RDWR, 0666);

  if(shm_fd > 0) {
    // 성공: 원하는 크기로 확장한다.
    printf("Creating shared memory and setting size=%d",
	SHM_SEGMENT_SIZE);
    
    if(ftruncate(shm_fd, SHM_SEGMENT_SIZE) < 0) {
      perror("ftruncate");
      exit(1);
    }

    /* 세마포어도 만든다. */
    demo_sem = sem_open(SEMA_NAME, O_RDWR | O_CREAT, 0666, 1);

    if(demo_sem == SEM_FAILED)
      perror("sem_open failed\n");
  }
  else if(shm_fd == -1 && errno == EEXIST){
    /* 이미 존재: O_CREAT 없이 다시 연다. */
    printf("Shared memory already exists.\n");
    shm_fd = shm_open(SHM_SEGMENT_NAME, O_RDWR, 0);
    demo_sem = sem_open(SEMA_NAME, O_RDWR);

    if(demo_sem == SEM_FAILED)
      perror("sem_open failed\n");
  }

  if(shm_fd == -1){
    perror("shm_open " SHM_SEGMENT_NAME);
    exit(1);
  }
  /* 공유 메모리를 매핑한다. */
  shm_p = mmap(NULL, SHM_SEGMENT_SIZE, PROT_READ | PROT_WRITE,
      MAP_SHARED, shm_fd, 0);

  if(shm_p == NULL){
    perror("mmap");
    exit(1);
  }
  return shm_p;
}

int main(int argc, char *argv[]){
  char *shm_p;
  printf("%s PID=%d\n", argv[0], getpid());
  shm_p = get_shared_memory();

  while(1){
    printf("Press enter to see the current contents of shm\n");
    getchar();
    
    printf("Waiting for semaphore...");
    fflush(stdout);
    sem_wait(demo_sem);
    printf(" done!\n"); 

    printf("%s\n",shm_p);
    /* 공유 메모리에 서명을 쓴다.*/
    sprintf(shm_p, "Hello from precess %d\n", getpid());
    sem_post(demo_sem);
  }
  return 0;
}
