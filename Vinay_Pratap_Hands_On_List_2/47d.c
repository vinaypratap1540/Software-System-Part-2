/*
============================================================================
Name : 47d.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create shared memory and perform the following operations: 
                   d.	Remove the shared memory  

============================================================================
*/

#include <stdio.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 47d
vinaypratap@Ubuntu:~$ cd 47d
vinaypratap@Ubuntu:~/47d$ code .
vinaypratap@Ubuntu:~/47d$ gcc 47d.c -o memory
vinaypratap@Ubuntu:~/47d$ ./memory

============================================================================
*/