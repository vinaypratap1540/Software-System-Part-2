/*
============================================================================
Name : 49c.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to implement a semaphore to protect any critical section: 
              c. Protect multiple pseudo resources (maybe two) using a counting semaphore   

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

int main() {
    struct sembuf op = {0, -1, 0};
    int semid = semget(ftok(".", 'd'), 1, 0);

    printf("pid %d waiting for a resource\n", getpid());
    semop(semid, &op, 1);
    printf("pid %d got a resource, free left: %d\n", getpid(), semctl(semid, 0, GETVAL));
    sleep(3);

    op.sem_op = 1;
    semop(semid, &op, 1);
    printf("pid %d released the resource\n", getpid());
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 49c
vinaypratap@Ubuntu:~$ cd 49c
vinaypratap@Ubuntu:~/49c$ code .
vinaypratap@Ubuntu:~/49c$ gcc 49c.c -o semaphore
vinaypratap@Ubuntu:~/49c$ ./semaphore
pid 14484 waiting for a resource
pid 14484 got a resource, free left: 1
pid 14484 released the resource

============================================================================
*/
