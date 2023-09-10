/*
============================================================================
Name : 9.c
Author : Gramya gupta
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 18th Aug, 2023.
============================================================================
*/



#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("error in arguements");
        return 1;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0) {
        perror("Error");
        return 1;
    }

    printf("File Information for: %s\n", argv[1]);
    printf("a. Inode: %ld\n", fileStat.st_ino);
    printf("b. Number of hard links: %ld\n", fileStat.st_nlink);
    printf("c. UID: %d\n", fileStat.st_uid);
    printf("d. GID: %d\n", fileStat.st_gid);
    printf("e. Size: %ld bytes\n", fileStat.st_size);
    printf("f. Block size: %ld bytes\n", fileStat.st_blksize);
    printf("g. Number of blocks: %ld\n", fileStat.st_blocks);

    // Convert and print time using ctime
    printf("h. Time of last access: %s", ctime(&fileStat.st_atime));
    printf("i. Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("j. Time of last change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

