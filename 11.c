/*
============================================================================
Name : 11.c
Author :Gramya Gupta
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 11th Aug, 2023.
 ============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Open the file for writing
    int orignalFile = open("newfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (orignalFile == -1) {
        perror("Error opening original file");
        return 1;
    }


    // Duplicate the file descriptor using dup
    int duplicateFile1 = dup(orignalFile);
    if (duplicateFile1 == -1) {
        perror("Error duplicating file descriptor");
        close(orignalFile);
        return 1;
    }
    int w1, w2;
    char buff1[]="Written using original file descriptor!!";
    char buff2[]="\n Written using duplicated file descriptor!!";
    

     printf("\n Duplicated file descriptor using dup system call and value is %d", duplicateFile1);
      w1 = write(orignalFile, buff1, sizeof(buff1)); //writing using original fd
       w2 = write(duplicateFile1, buff2, sizeof(buff2)); //writing using duplicated fd
      if(w1!=0 && w2!=0)
	      printf("\n Successfully written in file using both file descriptors...");
    
       close(duplicateFile1);





    // Duplicate the file descriptor using dup2
    
    int duplicateFile2 = dup2(orignalFile, 3);
    if (duplicateFile2 == -1) {
        perror("Error duplicating file descriptor with dup2");
        close(orignalFile);
        return 1;
    }
    int write1, write2;
    char buf1[]="Written using original file descriptor!!";
    char buf2[]="\n Written using duplicated file descriptor!!";
    
    printf("\n Duplicated file descriptor using dup2 system call and values is %d", duplicateFile2);
    write1 = write(orignalFile, buf1, sizeof(buf1)); //writing using original fd
    write2 = write(duplicateFile2, buf2, sizeof(buf2)); //writing using duplicated fd
    if(write1!=0 && write2!=0)
	    printf("\n Successfully written in file using both file descriptors...");
    
    close(duplicateFile2);




    // Append content to the file using originalFile descriptor
    int wr1, wr2;
    char b1[]="Written using original file descriptor!!";
    char b2[]="\n Written using duplicated file descriptor!!";
    int  fd2;
   
    fd2 = fcntl(orignalFile, F_DUPFD, 0);
    printf("\n Duplicated file descriptor using fcntl system call and values is  %d", fd2);
    wr1 = write(orignalFile, b1, sizeof(b1)); //writing using original fd
    wr2 = write(fd2, b2, sizeof(b2)); //writing using duplicated fd
    if(wr1!=0 && wr2!=0)
	    printf("\n Successfully written in file using both file descriptors...");
   
    close(fd2);


    // Close the originalFile descriptor
    close(orignalFile);

    printf("File descriptors duplicated and updated.\n");

    return 0;
}

