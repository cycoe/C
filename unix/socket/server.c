#include <arpa/inet.h>
#include <ctype.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_IP 127.0.0.1
#define SERVER_PORT 6666

int main(int argc, char *argv[])
{
  /* 声明 socket 文件描述符 */
  int lfd, cfd;
  /*  声明 socket 连接信息结构体 */
  struct sockaddr_in server_addr, client_addr;
  /*  声明一个变量用于储存 accept 返回的客户端 socket 的长度 */
  socklen_t client_sock_len;
  /*  缓冲区用于存储从 socket 中读取的字符串 */
  char buff[BUFSIZ];
  /*  读取的字节数 */
  int n;

  /*  初始化一个服务器 socket 文件描述符 */
  if ((lfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket error");
    exit(1);
  }

  /* 完成 server 的 socket 结构体 */
  server_addr.sin_family = AF_INET;
  /* 注意此处的 htons 函数用于将 short 类型的端口号转为大端序 */
  server_addr.sin_port = htons(SERVER_PORT);
  /* INADDR_ANY 宏得到本机可用的任何一个 IP */
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  /* 将 server_addr socket 信息绑定到 lfd 文件
   * 由于历史遗留问题，此处的 server_addr 要强转为 struct sockaddr 类型指针
   * 类似的函数有 accept, connect
   */
  if (bind(lfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind error");
    exit(1);
  }

  /* 设定允许同时连接的客户端最大数量 */
  listen(lfd, 128);

  /* 阻塞等待客户端连接
   * client_addr 结构体返回客户端信息
   * client_sock_len 返回结构体长度
   * 并且 accept 函数返回一个新的文件描述符指向与客户端配对的 socket 文件
   */
  client_sock_len = sizeof(client_addr);
  cfd = accept(lfd, (struct sockaddr *)&client_addr, &client_sock_len);
  printf("IP: %s, port: %d\n",
         inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, buff, sizeof(buff)),
         ntohs(client_addr.sin_port));

  while (1) {
    /* 从 socket 文件中读取最多 sizeof(buff) 个字符，实际读取个数是 n */
    n = read(cfd, buff, sizeof(buff));
    /* 转换为大写 */
    for (int i = 0; i < n; i++) {
      buff[i] = toupper(buff[i]);
    }
    /*
     * 将 buff 中的 n 个字符写入文件中
     * 此处千万不能写作 sizeof(buff)，否则后面的垃圾数据也会进入管道
     * read 和 write 并不对字符串进行处理，而是按字节读取
     */
    write(cfd, buff, n);
  }

  /* 关闭文件 */
  close(lfd);
  close(cfd);

  return 0;
}
