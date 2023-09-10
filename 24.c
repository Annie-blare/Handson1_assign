/*
============================================================================
Name : 24.c
Author : Gramya Gupta
Description : Write a program to create an orphan process.
Date: 1st sept, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<stdlib.h>
 int main(){
	 int Ppid=getpid();
	 int Cpid=fork();
	  
       printf("Parent pid=%d\n",Ppid);
       if(Cpid>0){
          printf("Welcome to Parent %d\n ",Cpid);
           exit(0); 
       }
       else{
       printf("Welcome to Child\n ");
       sleep(5);
       printf("parent pid is %d\n",getppid());
       if(Ppid!=getppid())
	         printf("Orphan created");
       }
return 0;
 }
