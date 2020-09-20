#include <unistd.h>
#include <wait.h>

#include <iostream>

int main() {
  pid_t pid1;
  pid_t pid2;
  int status;

  if (pid1 = fork()) {
    /* parent process A */
    waitpid(pid1, &status, 0);
  } else if (!pid1) {
    /* child process B */
    if (pid2 = fork()) {
      exit(0);
    } else if (!pid2) {
      /* child process C */
      int timeout = 5;
      while (timeout) {
        std::cout << "Will be terminated in " << (timeout--) << " sec.\n";
        sleep(1);
      }
    } else {
      /* error */
    }
  } else {
    /* error */
  }
}

