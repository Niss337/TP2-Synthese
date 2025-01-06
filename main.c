#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "constants.h"
#include "tftp_utils.h"
#include "pull.h"

void print_usage(const char *program_name) {
    fprintf(stderr, USAGE_MSG, program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
         }

    struct addrinfo hints = {0}, *res;
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_DGRAM; // UDP

    // Get address information for the specified host
    if (getaddrinfo(argv[2], TFTP_PORT, &hints, &res) != 0) {
        perror(GETADDRINFO_ERROR);
        return EXIT_FAILURE;
    }

    // Create a socket for communication
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror(SOCKET_ERROR);
         freeaddrinfo(res); // Free address information
        return EXIT_FAILURE;
    }

    // Check the command
    if (strcmp(argv[1], "gettftp") == 0) {
        
        send_rrq(sockfd, res, argv[3]);
        receive_packets(sockfd, argv[3]); 
    } else if (strcmp(argv[1], "puttftp") == 0) {
        // Execute the write operation
        send_wrq(sockfd, res, argv[3]); 
        send_data(sockfd, res, argv[3]); 
    } else {
        // Handle other commands
        fprintf(stderr, "Unrecognized command: %s\n", argv[1]);
        print_usage(argv[0]);
        close(sockfd);
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }
 freeaddrinfo(res); // Free address information
    close(sockfd); // Close the socket
    printf(FILE_TRANSFER_COMPLETE); // Indicate successful completion
    return EXIT_SUCCESS; // Indicate successful execution
}
