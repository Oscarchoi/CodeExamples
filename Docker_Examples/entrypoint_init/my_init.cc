#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>

#define STDIN_FILENO 0

// Signals we care about are numbered from 1 to 31, inclusive.
#define MAXSIG 31

void handle_signal(int signum) {
  std::cout << "[SIGNAL] Received singal " << signum << std::endl;

  if (signum == SIGCHLD) {
    int status, exit_status;
    pid_t killed_pid;
    while ((killed_pid = waitpid(-1, &status, WNOHANG)) > 0) {
      if (WIFEXITED(status)) {
        exit_status = WEXITSTATUS(status);
        std::cout << "A child with PID " << killed_pid
                  << " exited with exit status " << exit_status << std::endl;
      } else {
        assert(WIFSIGNALED(status));
        exit_status = 128 + WTERMSIG(status);
        std::cout << "A child with PID " << killed_pid
                  << " was terminated by signal " << (exit_status - 128)
                  << std::endl;
      }
    }
  }
}

// A dummy signal handler used for signals we care about.
void dummy(int signum) {}

int main(int argc, char** argv) {
  char** cmd = argv + 1;
  
  if ((char*)(*cmd) == 0) {
    std::cerr << "Empty argument for launch.\n";              
    return 0;
  }  

  sigset_t all_signals;
  sigfillset(&all_signals);
  sigprocmask(SIG_BLOCK, &all_signals, nullptr);

  for (int i = 1; i <= MAXSIG; i++) {
    signal(i, dummy);
  }

  // if (ioctl(STDIN_FILENO, TIOCNOTTY) == -1) {
  //   std::cerr << "Unable to detach from controlling tty (errno=%d %s).\n"
  //             << errno << strerror(errno);
  // } else {
  //   if (getsid(0) == getpid()) {
  //     std::cout
  //         << "Detached from controlling tty, ignoring the first SIGHUP and "
  //         << "SIGCONT we receive.\n";
  //     // signal_temporary_ignores[SIGHUP] = 1;
  //     // signal_temporary_ignores[SIGCONT] = 1;
  //   } else {
  //     std::cout
  //         << "Detached from controlling tty, but was not session leader.\n";
  //   }
  // }

  pid_t child_pid = fork();
  if (child_pid < 0) {
    std::cerr << "Unable to fork. Exiting.\n";
    return 1;
  } else if (child_pid == 0) {
    /* child */
    sigprocmask(SIG_UNBLOCK, &all_signals, NULL);

    if (setsid() == -1) {
      std::cerr << "Unable to setsid (errno= " << errno << "). Exiting.\n"
                << strerror(errno) << std::endl;
      exit(1);
    }

    if (ioctl(STDIN_FILENO, TIOCSCTTY, 0) == -1) {
      std::cerr << "Unable to attach to controlling tty (errno= " << errno
                << ").\n"
                << strerror(errno);
    }

    std::cout << "setsid complete.\n";

    execvp(cmd[0], &cmd[0]);

    // if this point is reached, exec failed, so we should exit nonzero
    std::cerr << cmd[0] << std::endl << strerror(errno) << std::endl;
    return 2;
  } else {
    /* parent */
    std::cout << "Child spawned with PID " << child_pid << std::endl;
    for (;;) {
      int signum;
      sigwait(&all_signals, &signum);
      handle_signal(signum);
    }
  }

  return 0;
}