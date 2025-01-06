#ifndef CONSTANTS_H
#define CONSTANTS_H

#define TFTP_PORT "1069"      // TFTP port to connect to
#define BUFFER_SIZE 516        // Maximum size of TFTP packets
#define TIMEOUT_SEC 5          // Timeout for receiving packets


#define USAGE_MSG "Usage: %s <host> <file>\n"
#define ERROR_OPENING_FILE "Error opening file for writing\n"
#define RECV_BLOCK_MSG "Received block %d\n"
#define FILE_TRANSFER_COMPLETE "File transfer complete.\n"
#define GETADDRINFO_ERROR "getaddrinfo\n"
#define SOCKET_ERROR "socket\n"
#define RECVFROM_ERROR "recvfrom\n"

#endif // CONSTANTS_H
