#include <asm-generic/errno-base.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

/* 打印错误信息并退出 */
void perr_exit(const char *msg) {
  perror(msg);
  exit(-1);
}

int accept_(int fd, struct sockaddr *addr, socklen_t *len) {
  int n;

  while ((n = accept(fd, addr, len)) < 0) {
    /* 当 accept 的返回值小于 0 时说明出错
     * accept 函数属于慢速系统调用，可能被系统中断，返回 -1
     * 并且置 errno 等于 ECONNABORTED（连接断开）或 EINTR（被系统中断）
     * 重启 accept
     */
    if (errno == ECONNABORTED || errno == EINTR)
      continue;
    else
      perr_exit("accept error");
  }

  return n;
}

int bind_(int fd, const struct sockaddr *addr, socklen_t len) {
  int n;

  if ((n = bind(fd, addr, len)) < 0)
    perr_exit("bind error");

  return n;
}

int connect_(int fd, const struct sockaddr *addr, socklen_t len) {
  int n;

  if ((n = connect(fd, addr, len)) < 0)
    perr_exit("connect error");

  return n;
}

int listen_(int fd, int backlog) {
  int n;
  if ((n = listen(fd, backlog)) < 0)
    perr_exit("listen error");

  return n;
}

int socket_(int family, int type, int protocol) {
  int n;

  if ((n = socket(family, type, protocol)) < 0)
    perr_exit("socket error");

  return n;
}

ssize_t read_(int fd, void *ptr, size_t nbytes) {
  ssize_t n;

  while ((n = read(fd, ptr, nbytes)) == -1) {
    if (errno == EINTR)
      continue;
    else
      return -1;
  }

  return n;
}

ssize_t write_(int fd, const void *ptr, size_t nbytes) {
  ssize_t n;

  while ((n = write(fd, ptr, nbytes)) == -1) {
    if (errno == EINTR)
      continue;
    else
      return -1;
  }

  return n;
}

int close_(int fd) {
  int n;

  if ((n = close(fd)) == -1)
    perr_exit("close error");

  return n;
}

/* 返回类型一定是 ssize_t，因为可能返回 -1 */
ssize_t readn(int fd, void *vptr, size_t n) {
  size_t nleft;
  ssize_t nread; /* 注意此处一定是 ssize_t 类型，有符号类型 */

  nleft = n; /* 剩余可读字节数 */

  while (nleft > 0 && (nread = read(fd, vptr, nleft)) != 0) {
    if (nread < 0) {
      if (errno != EINTR)
        return -1;
    } else {
      nleft -= nread;
      vptr += nread;
    }
  }

  return n - nleft;
}
