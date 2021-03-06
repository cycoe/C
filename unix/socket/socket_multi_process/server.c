#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#include "wrap.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6666

void wait_child(int signo) {
  while (waitpid(0, NULL, WNOHANG) > 0)
    ;
  return;
}

int main(int argc, char *argv[])
{
  /* 声明 socket 文件描述符 */
  int lfd, cfd;
  pid_t pid;
  /*  声明 socket 连接信息结构体 */
  struct sockaddr_in server_addr, client_addr;
  /*  声明一个变量用于储存 accept 返回的客户端 socket 的长度 */
  socklen_t client_sock_len;
  /*  缓冲区用于存储从 socket 中读取的字符串 */
  char buff[BUFSIZ];
  /*  读取的字节数 */
  int n;

  /*  初始化一个服务器 socket 文件描述符 */
  lfd = socket_(AF_INET, SOCK_STREAM, 0);

  /* 清空 server_addr */
  bzero(&server_addr, sizeof(server_addr));
  /* 完成 server 的 socket 结构体 */
  server_addr.sin_family = AF_INET;
  /* 注意此处的 htons 函数用于将 short 类型的端口号转为大端序 */
  server_addr.sin_port = htons(SERVER_PORT);
  /* INADDR_ANY 宏得到本机可用的任何一个 IP */
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  /* 或使用此方法转化一个 IP 字符串为网络字节序 */
  inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr.s_addr);

  /* 将 server_addr socket 信息绑定到 lfd 文件
   * 由于历史遗留问题，此处的 server_addr 要强转为 struct sockaddr 类型指针
   * 类似的函数有 accept, connect
   */
  bind_(lfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  /* 设定允许同时连接的客户端最大数量 */
  listen_(lfd, 128);

  signal(SIGCHLD, wait_child);

  /* 循环接收新的连接 */
  while (1) {
    /* 阻塞等待客户端连接
     * client_addr 结构体返回客户端信息
     * client_sock_len 返回结构体长度
     * 并且 accept 函数返回一个新的文件描述符指向与客户端配对的 socket 文件
     */
    client_sock_len = sizeof(client_addr);
    cfd = accept_(lfd, (struct sockaddr *)&client_addr, &client_sock_len);
    printf("IP: %s, port: %d connected!\n",
           inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, buff, sizeof(buff)),
           ntohs(client_addr.sin_port));

    /* 当建立连接后，fork 出一个新进程 */
    if ((pid = fork()) < 0) {
      perr_exit("fork error");
    } else if (pid == 0) {
      /* 子进程进行数据的接收与处理 */
      close(lfd);
      break;
    } else {
      /* 父进程继续监听新的连接 */
      close(cfd);
    }
  }

  if (pid == 0) {
    /* 从 socket 文件中读取最多 sizeof(buff) 个字节，实际读取个数是 n 个字节 */
    while ((n = read_(cfd, buff, sizeof(buff))) > 0) {
      /* 转换为大写
       * 此处是 n 是因为刚好一个字符是一个字节
       * 否则应该是 i < n / sizeof(type)
       */
      for (int i = 0; i < n; i++) {
        buff[i] = toupper(buff[i]);
      }
      /*
       * 将 buff 中的 n 个字节写入文件中
       * 此处千万不能写作 sizeof(buff)，否则后面的垃圾数据也会进入管道
       * read 和 write 并不对字符串进行处理，而是按字节读取
       */
      write_(cfd, buff, n);
    }

    if (n == -1)
      perr_exit("read error");

    /* 关闭文件 */
    close_(cfd);

    printf(
        "IP: %s is disconnected!\n",
        inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, buff, sizeof(buff)));
  }

  return 0;
}
