/*
============================================================================
Name : 18b.c
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
#include<stdbool.h> 
#include<fcntl.h>
#include<stdlib.h>

//initializing an array of structure to store data of trains

struct traindb{
  int train;
  int seats;
  bool available;
}db;

int main()
{
  char dbname[] = "trainDataBase.txt";
  int i, fd, num, res;
  struct flock lc;
  //setting lock parameters
  lc.l_type = F_WRLCK;

  lc.l_whence = SEEK_SET;
  lc.l_pid = getpid();

  fd = open(dbname, O_RDWR, 0744);
  printf("\n Available trains are : 1, 2, 3 \n ");
  //close(fd);
  printf("\n Enter Train No. to book tickets : or enter 0 to exit!! ");
  scanf("%d", &num);
 
  //setting start and length of the lock structure
  lc.l_start = (num-1)*sizeof(db);
  lc.l_len = sizeof(db);

  printf("\n Waiting in the reservation queue...\n");
  //setting lock
  fcntl(fd, F_SETLKW, &lc);
  //reading the data from the database
  lseek(fd,(num-1)*sizeof(db) ,SEEK_SET);  //decide where to read from
  read(fd, &db, sizeof(db));
  if(db.available)
          {
                printf("\n Reserving for Train%d", db.train);
                printf("\n No. of tickets available = %d", db.seats);
                ask : printf("\n Enter no. of tickets to reserve: ");
                scanf("%d", &res);
                if(db.seats - res < 0){
                  printf("\n Sorry unable to book more than available !!!");
                  goto ask;
                }
                db.seats -= res;
                if(db.seats == 0) db.available = false;
                // to move the cursor to the second array element of db structure
		lseek(fd, -1*sizeof(db), SEEK_CUR); //get back to start of the ith db structure  from curent pointer
                write(fd, &db, sizeof(db));
                printf("\n %d tickets reserved for Train%d", res, db.train);
                lc.l_type = F_UNLCK;
                fcntl(fd, F_SETLK, &lc);
          }
          close(fd);
  return 0;
}
