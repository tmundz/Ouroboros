#ifndef WEBCLIENT_H
#define WEBCLIENT_H
#include "common.h"
// web browser port
#define SERVER_PORT 80

#define MAXLINE 4096
#define SOCKA struct sockaddr

void err_n_die(const char *fmt, ...);

#endif
