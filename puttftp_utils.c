#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "constants.h"
#include "pull.h"


// Function to send a Write Request (WRQ) to the TFTP server
void send_wrq(int sockfd, struct addrinfo *res, const char *file) {
    char buffer[BUFFER_SIZE];
    int filename_len = strlen(file);
    const char *mode = "octet";  // Mode for binary transfer
    int mode_len = strlen(mode);

    // Build the WRQ packet
    buffer[0] = 0;               // Opcode MSB
    buffer[1] = 2;               // Opcode LSB (WRQ)
    memcpy(buffer + 2, file, filename_len);
      buffer[2 + filename_len] = 0; // Null byte after the filename
    memcpy(buffer + 3 + filename_len, mode, mode_len);
    buffer[3 + filename_len + mode_len] = 0; 

    // Send the WRQ to the server
    sendto(sockfd, buffer, 4 + filename_len + mode_len, 0, res->ai_addr, res->ai_addrlen);
}// Function to send data packets to the TFTP server
void send_data(int sockfd, struct addrinfo *res, const char *local_file) {
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen(local_file, "rb");
    if (!fp) {
        perror(ERROR_OPENING_FILE);
        return;
    }

    int block_number = 1;
    while (1) {
         // Read data into buffer
        int bytes_read = fread(buffer + 4, 1, BUFFER_SIZE - 4, fp);
        if (bytes_read < 0) {
            perror(ERROR_READING_FILE);
            break;
        }

        // Prepare the data packet
        buffer[0] = 0; // Opcode MSB
        buffer[1] = 3; // Opcode LSB (DATA)
        buffer[2] = block_number >> 8; // Block number MSB
        buffer[3] = block_number & 0xFF; // Block number LSB
        // Send the data packet
        sendto(sockfd, buffer, bytes_read + 4, 0, res->ai_addr, res->ai_addrlen);
        
        // Check if this is the last block
        if (bytes_read < BUFFER_SIZE - 4) {
            break; // Last block sent
        }
        block_number++;
    }

    fclose(fp); // Close the file after sending
}
