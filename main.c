#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define USAGE_MSG "Usage: %s <host> <file>\n"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, USAGE_MSG, argv[0]);
        return 1;
    }
    const char *host = argv[1];     // Server address
    const char *filename = argv[2]; // File to be transferred

    // Display the host and filename
    printf("Host: %s, File: %s\n", host, filename);

    struct addrinfo hints = {0}, *res;
    hints.ai_family = AF_INET;      // Use IPv4
    hints.ai_socktype = SOCK_DGRAM; // Use UDP

    if (getaddrinfo(host, "1069", &hints, &res) != 0)
    {
        perror("getaddrinfo");
        return 1;
    }
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &((struct sockaddr_in *)res->ai_addr)->sin_addr, ipstr, sizeof(ipstr));
    printf("Resolved IP address: %s\n", ipstr);

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
    {
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }
    printf("Socket created successfully.\n");
    freeaddrinfo(res);
    close(sockfd); // Close the socket
    return 0;
}
