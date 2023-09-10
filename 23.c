/*
============================================================================
Name : 23.c
Author : Gramya Gupta
Description : Write a program to create a Zombie state of the running program.
Date: 25th Aug, 2023.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t childPid=fork();
        


	if(childPid<0){
		perror("unsucessful child creation");
	}
	 if(childPid==0){
		 printf("Inside Child\n");
		 printf("Child is exiting\n");
		 exit(0);
	 }
	 else{
		 printf("Inside parent\n");
		 sleep(5);
		 printf("still Inside parent ,child exited while i was busy\n ");
		

              }
	 
	 return 0;
}
