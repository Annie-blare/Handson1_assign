/*
============================================================================
Name : 2.c
Author : Gramya Gupta
Description :Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 5th Aug, 2023.
============================================================================
*/
#include<stdio.h>
int main(){
    for(;;);
    return 0;

// to run in background use - ./a.out &
//go to proc directory - cd /proc
// find the folder with the process id
// cd pid
// cat status to see all status about your process


}
