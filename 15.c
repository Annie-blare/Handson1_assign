/*
============================================================================
Name : 15.c
Author : Gramya Gupta
Description : Write a program to display the environmental variable of the user (use environ).
Date: 26th Aug, 2023.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

extern char **environ; // Declare the environ variable

int main() {
    // Iterate through the environment variables using environ
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}

