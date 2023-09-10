/*
============================================================================
Name : 27c.c
Author :Gramya Gupta
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
#include<stdlib.h>
#include<unistd.h>

int main(){
  printf("Before Executing execle()");
  execle("/bin/ls","ls","-RL",NULL,NULL);
  printf("Unsuccesful Execution of execle()");
  return 0;
}




