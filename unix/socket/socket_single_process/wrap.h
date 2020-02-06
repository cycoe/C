#ifndef __WRAP_H_
#define __WRAP_H_

void perr_exit(const char *msg);
int accept_(int fd, struct sockaddr *addr, socklen_t *len);
int bind_(int fd, const struct sockaddr *addr, socklen_t len);
int connect_(int fd, const struct sockaddr *addr, socklen_t len);
int listen_(int fd, int backlog);
int socket_(int family, int type, int protocol);
ssize_t read_(int fd, void *ptr, size_t nbytes);
ssize_t write_(int fd, const void *ptr, size_t nbytes);
int close_(int fd);

#endif
