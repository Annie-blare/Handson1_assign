/*
============================================================================
Name : 7.c
Author : Gramya Gupta
Description :Write a program to copy file1 into file2 ($cp file1 file2). 
Date: 11th Aug, 2023.
============================================================================
*/



#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[]) {
         if(argc!=3) {
		 printf("You are useless");   //handling missing information
         return 1;
   }		 

	int fd_read =open(argv[1],O_RDONLY);
	int fd_write=open(argv[2],O_WRONLY |O_CREAT);  //handling nonexsisting file
	if(fd_read==-1 || fd_write==-1) 
		 perror("useless");
	while(1){
	char buf;
    int char_read=read(fd_read,&buf,1);
    if(char_read==0)
	    break;
    int char_write=write(fd_write,&buf,1);
	}
	int fd_read_close= close(fd_read);
	int fd_write_close= close(fd_write);

	if(fd_read==-1 || fd_write==-1){
                 perror("useless");
		 return 1;
     }		 
//gcc 7.c -o copy
// ./copy file1.txt gramya.txt
// cat gramya.txt
return 0;
}



