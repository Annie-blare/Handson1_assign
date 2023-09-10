/*
============================================================================
Name : 27b.c
Author : Gramya Gupta
Description :Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 7th sept, 2023.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	printf("Before Executing execlp()");
	execlp("ls","ls","-RL",NULL);
	printf("After executing execlp()");//ERROR CHECK
	return 0;
}

