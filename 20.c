/*
============================================================================
Name : 20.c
Author :Gramya Gupta
Description :Find out the priority of your running program. Modify the priority with nice command. 
Date: 25th Aug, 2023.
============================================================================
*/




#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char * argv[]){
	if(argc<2){
		perror("Pass complete command");
		return 1;
	}
	else{

		
	
	  //check priority of running process
	  printf("Current priority of %d processID is %d",getpid(),nice(0));

	  //set priority of running process 
	  
	  printf("New priority of running process is se to %d",nice(atoi(argv[1])));

        }

	  return 0;

	}	  
