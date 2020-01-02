#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t child_pid;
  printf("The process id of main process is %u\n", getpid());
  child_pid = fork();

  // After forking, the parent process will get the pid of the child, and the
  // child process will get 0
  if (child_pid != 0) {
    printf("This is the parent process, with pid %u\n", getpid());
    printf("The child pid is %u\n", child_pid);
  } else {
    printf("This is the child process, with pid %u\n", getpid());
    printf("The parent pid is %u\n", getppid());
  }

  return 0;
}
