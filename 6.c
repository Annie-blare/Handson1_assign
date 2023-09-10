/*
============================================================================
Name : 6.c
Author : Gramya Gupta
Description :Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
Date: 11th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void){
	int fd;
	char buf[80];
  int read_count =read(0,buf,sizeof(buf));
  printf(" Writing data on console after reading /n");
	write(1, buf, read_count);
	//fd=0 is standard input file descripter
	//fd=1 is standard output file descripter
	close(0);
	close(1);
	return 0;
}	
	
