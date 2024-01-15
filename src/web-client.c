#include "web-client.h"
#include <arpa/inet.h>
#include <sys/socket.h>

void err_n_die(const char *fmt, ...) {
  int errno_save;
  va_list ap;

  // save the errno
  errno_save = errno;

  // print fmt+ args to stdout
  va_start(ap, fmt);
  vfprintf(stdout, fmt, ap);
  fprintf(stdout, "\n");
  fflush(stdout);

  if (errno_save != 0) {
    fprintf(stdout, "(errno = %d) : %s\n", errno_save, strerror(errno_save));
    fprintf(stdout, "\n");
    fflush(stdout);
  }
  va_end(ap);

  exit(1);
}

int main(int argc, char **argv) {
  int sockfd, n, sendbytes;
  struct sockaddr_in servaddr;
  char sendline[MAXLINE];
  char recvline[MAXLINE];

  if (argc != 2)
    err_n_die("usage: %s <server address>", argv[0]);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    err_n_die("Error while creating the socket!");

  // set all of the serv addr to 0
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET; // internet address
  servaddr.sin_port =
      htons(SERVER_PORT); // converts to the network std byte order

  // convert text to byte
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    err_n_die("inet_pton error for %s ", argv[1]);
}
