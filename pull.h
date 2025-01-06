#ifndef PULL_H
#define PULL_H

#include <netdb.h>

void send_wrq(int sockfd, struct addrinfo *res, const char *file);
void send_data(int sockfd, struct addrinfo *res, const char *local_file);

#endif 
