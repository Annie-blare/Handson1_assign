/*
============================================================================
Name : 8.c
Author : Gramya Gupta
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 18th Aug, 2023.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("1.c", O_RDONLY);

    if (fd == -1) {
        perror("Failed to open the file");
        return 1;
    }

    char buffer[256];
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            putchar(buffer[i]);
            if (buffer[i] == '\n') {
                putchar('\n');
            }
        }
    }

    if (bytesRead == -1) {
        perror("Read error");
        return 1;
    }

    close(fd);

    return 0;
}

