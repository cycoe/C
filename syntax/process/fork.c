#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 声明 pid_t 类型的变量，用于存储 pid
    pid_t pid;
    int stat_val;

    // 调用 fork 函数时，会在此处分裂成两个进程
    // 父进程拿到子进程的 pid，子进程拿到 0
    // 类似于 GPU 编程，此 fork 往后的所有语句，两个进程都会执行
    pid = fork();

    // 当 fork 出错时，会返回一个小于 0 的 pid
    if (pid < 0) {
        perror("Fork failed!");
        exit(1);
    }

    if (pid == 0) {
        printf("This is the child process, child pid=%d\n", getpid());
        sleep(20);
    }
    else {
        printf("This is the parent process, child pid=%d, parent pid=%d\n", pid, getpid());
        // 等待一个指定的进程，返回值写入 stat_val 中
        waitpid(pid, &stat_val, 0);
        // WIFEXITED 宏检查是否是正常返回
        if (WIFEXITED(stat_val))
            // WEXITSTATUS 宏获取返回值
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else if (WIFSIGNALED(stat_val))
            // WTERMSIG 获取信号值
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
    }
    return 0;
}
