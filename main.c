#include <stdio.h>
#include <stdlib.h>

// Function to handle command-line arguments
void handle_arguments(int argc, char *argv[], const char **host, const char **filename) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <file>\n", argv[0]);
        exit(1); // Exit on error
    }
    *host = argv[1]; // Retrieve the host
    *filename = argv[2]; // Retrieve the filename
}
// Main function 
int main(int argc, char *argv[]) {
    const char *host;
    const char *filename;

    // Handle command-line arguments
    handle_arguments(argc, argv, &host, &filename);
    printf("Host: %s, File: %s\n", host, filename);

    return 0; 
}
