/*
============================================================================
Name : 16a.c
Author : Gramya Gupta
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 25th Aug, 2023.
============================================================================
*/


#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
  struct flock lc;
  int r, fd;
  //decribing lock and initializing lc object 
  lc.l_type = F_WRLCK;
  lc.l_whence = SEEK_SET;
  lc.l_start = 0;
  lc.l_len = 0;
  lc.l_pid = getpid();

  printf("\n block before critical section");
  fd = open("testfile.txt", O_CREAT | O_RDWR, 0744);
  r = fcntl(fd, F_SETLKW, &lc); //setlckw waits for other process to release lock

  if(r==-1) printf("\n ERRORgetting lock!");  

  //crritical section
  printf("\n Inside critical scetion!!");
  printf("\n enter any key to exit critical section : ");
  getchar();

  lc.l_type = F_UNLCK;
  r = fcntl(fd, F_SETLK, &lc); //release the lock

  if(r==-1) printf("\n error unlocking the file");

  printf("\n Out of critical section.");
  return 0;
}
