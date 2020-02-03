#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6666

int main(int argc, char *argv[])
{
  int cfd;
  struct sockaddr_in server_addr;
  // socklen_t server_addr_len;
  char buff[BUFSIZ];
  int n;

  cfd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr.s_addr);

  connect(cfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  while (1) {
    fgets(buff, sizeof(buff), stdin);
    write(cfd, buff, strlen(buff));
    n = read(cfd, buff, sizeof(buff));
    write(STDOUT_FILENO, buff, n);
  }

  close(cfd);

  return 0;
}
