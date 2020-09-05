#include <poll.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <vector>

#ifndef __NR_pidfd_open
#define __NR_pidfd_open 434 /* System call # on most architectures */
#endif

static int pidfd_open(pid_t pid, unsigned int flags) {
  return syscall(__NR_pidfd_open, pid, flags);
}

int main(int argc, char **argv) {
  std::vector<int> pid_list;
  for (int i = 1; i < argc; i++) pid_list.emplace_back(atoi(argv[i]));

  int nfds = pid_list.size();
  if (!nfds) return 0;

  struct pollfd pollfds[nfds];

  for (int i = 0; i < nfds; i++) {
    int pidfd = pidfd_open(pid_list[i], 0);
    if (pidfd == -1) {
      std::cerr << "pidfd_open" << std::endl;
      return -1;
    }

    struct pollfd pollfd;
    pollfds[i].fd = pidfd;
    pollfds[i].events = POLLIN;
  }

  int open_fds = nfds;
  while (open_fds > 0) {
    std::cout << "About to poll()..." << std::endl;
    if (poll(pollfds, nfds, -1) == -1) {
      std::cerr << "poll" << std::endl;
      exit(EXIT_FAILURE);
    }

    for (int j = 0; j < nfds; j++) {
      if (pollfds[j].revents != 0) {
        if (pollfds[j].revents & POLLIN) {
          std::cout << "Process exit detected... "
                    << "  closing fd " << pollfds[j].fd << std::endl;
          if (close(pollfds[j].fd) == -1) exit(EXIT_FAILURE);
          open_fds--;
        }
      }
    }
  }
  std::cout << "All file descriptors closed; bye" << std::endl;
  return 0;
}