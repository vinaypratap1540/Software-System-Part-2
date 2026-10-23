/*
============================================================================
Name : 48b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create a semaphore and initialize its value: 
                b.	Create a counting semaphore 
 
============================================================================
*/

#include <stdio.h>
#include <sys/sem.h>

union semun {
    int val;
};

int main() {
    union semun arg;
    int semid = semget(ftok(".", 'd'), 1, IPC_CREAT | 0644);
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);
    printf("Counting semaphore id: %d, value: %d\n", semid, semctl(semid, 0, GETVAL));
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 48b
vinaypratap@Ubuntu:~$ cd 48b
vinaypratap@Ubuntu:~/48b$ code .
vinaypratap@Ubuntu:~/48b$ gcc 48b.c -o semaphore
vinaypratap@Ubuntu:~/48b$ ./semaphore
Counting semaphore id: 2, value: 2

============================================================================
*/