#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 80

// 此处演示了如何利用管道进行进程间通讯
int main(int argc, char *argv[])
{

    // 用于存储读取的字节数
    int n;
    // 管道文件描述符
    int fd[2];
    pid_t pid;
    // 字符串缓冲区
    char buff[BUFFSIZE];

    if (pipe(fd) < 0) {
        perror("Pipe failed");
        exit(1);
    }

    if ((pid = fork()) < 0) {
        perror("Fork failed");
        exit(1);
    }

    // 父进程向管道中写入
    if (pid > 0) {
        printf("Parent pid=%d, child pid=%d\n", getpid(), pid);
        // 关闭读取管道，对于每个进程来说，fd[0] 都是读取，fd[1] 都是写入
        close(fd[0]);
        // 写入字符串，长度为 11
        write(fd[1], "hello world", 11);
        // 等待 1 秒后再次写入
        // 此处是否等待产生的结果会不同
        // 1. 如果两次写入中间有间隔，即无法优化成一次写入，
        //    则子进程读取时只会读出第一次写入的内容
        // 2. 如果没有间隔，则会优化为将两次写入合并为一次写入到管道中
        sleep(1);
        write(fd[1], "hello world", 11);
        // 等待其他进程结束
        wait(NULL);
    }
    else {
        printf("Child pid=%d\n", getpid());
        // 关闭写入管道
        close(fd[1]);
        // 从 fd[0] 中读取字符到 buff 中，buff 的大小为 BUFFSIZE，实际读取长度为 n
        n = read(fd[0], buff, BUFFSIZE);
        buff[n] = '\0';
        printf("Message recieved from parent: %s\n", buff);
    }
    return 0;
}
