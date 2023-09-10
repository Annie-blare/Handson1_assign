/*
============================================================================
Name : 21.c
Author : Gramya Gupta
Description : Write a program, call fork and print the parent and child process id.
Date: 25th sept, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	int val=fork();
	if(val==0){
		printf("Hi I am Child and My Pid is %d\n",getpid());
	}
	else{
		printf("Hi I am Parent and My Pid is %d\n",getpid());

	   }
   return 0;
}   
