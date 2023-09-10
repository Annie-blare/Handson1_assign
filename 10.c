/*
============================================================================
Name : 10.c 
Author : Gramya Gupta
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 25th Aug, 2023.
============================================================================
*/





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Open the file in read-write mode
    int fileDescriptor = open("newfile.txt", O_RDWR | O_CREAT, 0644);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write 10 bytes
    const char data1[] = "abcdefghij";
    ssize_t bytesWritten1 = write(fileDescriptor, data1, 10);
    if (bytesWritten1 != 10) {
        perror("Error writing to file");
        close(fileDescriptor);
        return 1;
    }

    // Move the file pointer by 10 bytes using lseek
    off_t newPosition = lseek(fileDescriptor, 10, SEEK_CUR);
    if (newPosition == -1) {
        perror("Error seeking in file");
        close(fileDescriptor);
        return 1;
    }

    // Write another 10 bytes
    const char data2[] = "klmnopqrst";
    ssize_t bytesWritten2 = write(fileDescriptor, data2, 10);
    if (bytesWritten2 != 10) {
        perror("Error writing to file");
        close(fileDescriptor);
        return 1;
    }

    // Close the file
    close(fileDescriptor);

    printf("File operations completed.\n");
    return 0;
}

