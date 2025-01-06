#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "constants.h"
#include "tftp_utils.h"

// Function to send a Read Request (RRQ) to the TFTP server
void send_rrq(int sockfd, struct addrinfo *res, const char *file) {
    char buffer[BUFFER_SIZE];
    int filename_len = strlen(file);
    const char *mode = "octet";  // Mode for binary transfer
    int mode_len = strlen(mode);

    // Build the RRQ packet
    buffer[0] = 0;               // Opcode MSB
    // This is the first byte of the opcode, which is always 0 for TFTP Read Request (RRQ).
    buffer[1] = 1;               // Opcode LSB (RRQ)
    // This is the second byte of the opcode, which is set to 1 to indicate a Read Request (RRQ) operation in TFTP.
    memcpy(buffer + 2, file, filename_len);
     buffer[2 + filename_len] = 0; // Null byte after the filename
    memcpy(buffer + 3 + filename_len, mode, mode_len);
    buffer[3 + filename_len + mode_len] = 0; 

    // Send the RRQ to the server
    sendto(sockfd, buffer, 4 + filename_len + mode_len, 0, res->ai_addr, res->ai_addrlen);
}
// Function to receive packets from the TFTP server
void receive_packets(int sockfd, const char *remote_file) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_storage server_addr;
    socklen_t addr_len = sizeof(server_addr);
    int block_number = 1; // Initialize block number for ACK

    // Set timeout for receiving packets
    struct timeval tv = {TIMEOUT_SEC, 0};
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    // Open the file for writing 
    // This is essential for creating a new file or overwriting an existing one to store 
    FILE *fp = fopen(remote_file, "wb");
    if (!fp) {
        perror(ERROR_OPENING_FILE);
        return;
    }

    while (1) {
        // Receive data from the server
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&server_addr, &addr_len);
        if (n < 0) {
            perror(RECVFROM_ERROR);
            break; // in case error
        }
// Check if it is a data packet
        if (buffer[1] == 3 && (buffer[2] << 8 | buffer[3]) == block_number) {
            // Write the data to file
            fwrite(buffer + 4, 1, n - 4, fp);
            printf(RECV_BLOCK_MSG, block_number);
            
            // Send ACK for the received block
            char ack[4] = {0, 4, buffer[2], buffer[3]};
            sendto(sockfd, ack, sizeof(ack), 0, (struct sockaddr*)&server_addr, addr_len);
             block_number++; 
            if (n < BUFFER_SIZE) break; // Last block received
        }
    }

    fclose(fp); // Close the file after writing we done 
}
