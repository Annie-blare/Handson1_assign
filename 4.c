/*
============================================================================
Name : 4.c
Author : Gramya Gupta
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 11th Aug, 2023.
============================================================================
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd;
	char buf[80];
	char fn[]="test1.file";

	fd=open(fn, O_EXCL | O_RDWR, 0744);
	read(fd, buf, sizeof(buf));
	printf(" contents in file are : %s\n", buf);
	close(fd);
return 0;
}
