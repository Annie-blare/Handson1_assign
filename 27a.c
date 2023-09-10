/*
============================================================================
Name : 27a.c
Author : Gramya Gupta
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 7th sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
     
	printf("Before calling execl()");
	execl("/bin/ls","ls","-RL",NULL);
	printf("After executing execl()");//error check
	return 0;
}

