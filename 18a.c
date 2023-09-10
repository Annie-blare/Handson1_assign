/*
============================================================================
Name : 18a.c
Author : Gramya Gupta
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition
Date: 25th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
struct trainDB{
  int train_no;
  int available_seats;
  bool available;
};

int main()
{
  struct trainDB db[3];
  int i,fd;
  char dbname[]="trainDataBase.txt";

  //initializing train and tickets availaible
  for(i=0; i<3; i++)
  {
   db[i].train_no = i+1;
   db[i].available_seats = 10 + i*5;
   db[i].available = true;
  }


  fd = open(dbname , O_CREAT | O_WRONLY , 0744);
  write(fd, &db, sizeof(db));
  close(fd);

  //checking whether i can read data from the trainsDB file
  fd = open(dbname, O_RDONLY);
  for(i=0; i<3;i++)
  {
    read(fd, &db[i], sizeof(db[i]));
    printf("\n %d %d", db[i].train_no, db[i].available_seats);
  }
  close(fd);
  
  return 0;
}
