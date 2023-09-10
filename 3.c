/*
============================================================================
Name : 3.c
Author : Gramya Gupta
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 5th Aug, 2023.
============================================================================
*/



#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
int fd;
char fn[]="test.file";
if(creat(fn, 0744)!=-1)
       	printf("\n file created successfully!\n");
else
    printf("\n error!!\n");

fd = open(fn, O_RDWR);
printf("\n fd = %d\n", fd);

close(fd);

return 0;
}
