#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

static void sig_int(int);

int main(int argc, char *argv[]) {
  char buff[1024];
  pid_t pid;
  int status;

  if (signal(SIGINT, sig_int) == SIG_ERR) {
    fputs("Signal error!\n", stderr);
  }

  printf("%% ");
  // fgets 每次从标准输入中读取一行，当键入文件结束符时，fgets 返回一个 NULL
  // 指针
  while (fgets(buff, 1024, stdin) != NULL) {
    if (buff[strlen(buff) - 1] == '\n')
      buff[strlen(buff) - 1] = 0;

    // fork 失败会返回一个小于 0 的 pid
    if ((pid = fork()) < 0) {
      fputs("Fork error!\n", stderr);
    } else if (pid == 0) {
      execlp(buff, buff, (char *)0);
      fputs("Couldn't execute\n", stderr);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      fputs("waitpid error!\n", stderr);
    }
    printf("%% ");
  }

  return 0;
}

void sig_int(int signo) { printf("interrupt: signal is %d\n%% ", signo); }
