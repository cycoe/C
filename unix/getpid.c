#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("The process ID is %u\n", getgid());
  printf("The parent process is %u\n", getppid());

  return 0;
}
