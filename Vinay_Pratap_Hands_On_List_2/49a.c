/*
============================================================================
Name : 49a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to implement a semaphore to protect any critical section: 
               a.	Rewrite the ticket number creation program using a semaphore 

 
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sem.h>

int main() {
    char buf[20] = {0};
    struct sembuf op = {0, -1, 0};
    int semid = semget(ftok(".", 'c'), 1, 0);
    int fd = open("files/ticket49.txt", O_RDWR | O_CREAT, 0644);

    printf("Waiting to enter critical section\n");
    semop(semid, &op, 1);
    printf("Inside critical section\n");

    read(fd, buf, sizeof(buf));
    int ticket = atoi(buf) + 1;
    lseek(fd, 0, SEEK_SET);
    dprintf(fd, "%d\n", ticket);
    printf("New ticket number: %d\n", ticket);
    sleep(3);

    op.sem_op = 1;
    semop(semid, &op, 1);
    printf("Left critical section\n");
    close(fd);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 49a
vinaypratap@Ubuntu:~$ cd 49a
vinaypratap@Ubuntu:~/49a$ code .
vinaypratap@Ubuntu:~/49a$ gcc 49a.c -o semaphore
vinaypratap@Ubuntu:~/49a$ ./semaphore
Waiting to enter critical section
Inside critical section
New ticket number: 1
Left critical section

============================================================================
*/