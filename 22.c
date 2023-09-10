/*
============================================================================
Name : 22.c
Author : Gramya Gupta
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 1st sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
   int fileDescriptor = open("gramya.txt", O_RDWR | O_CREAT, 0644);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }
   int pid1,pid2;
       if(fork()){

           const char data1[] = "Hi I am Parent";
    ssize_t bytesWritten1 = write(fileDescriptor, data1, sizeof(data1)-1);
    if (bytesWritten1 ==-1) {
        perror("Error writing to file");
        close(fileDescriptor);
        return 1;
    }


       }
       else{
       const char data1[] = "Hi I am Child";
    ssize_t bytesWritten1 = write(fileDescriptor, data1, sizeof(data1)-1);
    if (bytesWritten1==-1) {
        perror("Error writing to file");
        close(fileDescriptor);
        return 1;
    }
       
       }
return 0;

}
