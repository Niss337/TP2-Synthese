#ifndef CONSTANTS_H
#define CONSTANTS_H

#define TFTP_PORT "1069"
#define BUFFER_SIZE 512
#define TIMEOUT_SEC 5
#define USAGE_MSG "Usage: %s <command> <server> <filename>\n"
#define SOCKET_ERROR "Failed to create socket"
#define GETADDRINFO_ERROR "Failed to get address info"
#define FILE_TRANSFER_COMPLETE "File transfer completed successfully\n"
#define ERROR_OPENING_FILE "Error opening file"
#define ERROR_READING_FILE "Error reading file"
#define RECVFROM_ERROR "Error receiving data"
#define RECV_BLOCK_MSG "Received block number: %d\n"

#endif // CONSTANTS_H
