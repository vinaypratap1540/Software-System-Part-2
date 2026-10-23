/*
============================================================================
Name : 49d.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to implement a semaphore to protect any critical section: 
              d.	Remove the created semaphore   

============================================================================
*/

#include <sys/sem.h>

int main() {
    semctl(semget(ftok(".", 'c'), 1, 0), 0, IPC_RMID);
    semctl(semget(ftok(".", 'd'), 1, 0), 0, IPC_RMID);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 49d
vinaypratap@Ubuntu:~$ cd 49d
vinaypratap@Ubuntu:~/49d$ code .
vinaypratap@Ubuntu:~/49d$ gcc 49d.c -o semaphore
vinaypratap@Ubuntu:~/49d$ ./semaphore

============================================================================
*/