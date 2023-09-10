/*
============================================================================
Name : 25.c
Author : Gramya Gupta
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 1st Sept,2023
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int C1,C2,C3;
	C1=fork();
	if(C1==0){
		printf("Inside child1");
		sleep(5);
		printf("GoodBye child1");
	}
	
	else if((C2=fork())==0){
		printf("Inside child2");
		sleep(10);
                printf("GoodBye child2");// child2 has became orphan now
	}
       else if((C3=fork())==0){
	       printf("Inside child3");
	       sleep(12);
	       printf("GoodBye child3");
             }
	else{
		waitpid(C1,NULL,0);
	       printf("GoodBye Parent");
          }
  return 0;
}  



