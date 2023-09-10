/*
============================================================================
Name : 5.c
Author : Gramya Gupta
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.`
Date: 11th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int fd1,fd2,fd3,fd4,fd5;
	fd1=open("F1",O_CREAT|O_RDONLY|O_EXCL);
	fd2=creat("F2",O_RDONLY|O_EXCL);
	fd3=creat("F3",O_RDWR|O_EXCL);
	fd4=creat("F4",O_RDWR|O_EXCL);
	fd5=creat("F5",O_RDWR|O_EXCL);
	printf("%d",fd1);
	for(;;);
    // do ./a.out &
    // change directory to proc 
    // do \proc\pid\fd



	return 0;
	
}	
