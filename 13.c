/*
============================================================================
Name : 13.c
Author : Gramya Gupta
Description : 
Date: 25th Aug, 2023.
============================================================================
*/





#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // Set up the file descriptor set for stdin
    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(STDIN_FILENO, &readSet);

    // Set timeout to 10 seconds
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    // Wait for input on stdin using select
    int result = select(STDIN_FILENO + 1, &readSet, NULL, NULL, &timeout);

    if (result == -1) {
        perror("Error in select");
        return 1;
    } else if (result == 0) {
        printf("No data available within 10 seconds.\n");
    } else {
        printf("Data is available within 10 seconds.\n");
    }

    return 0;
}

