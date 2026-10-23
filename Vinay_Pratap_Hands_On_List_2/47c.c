/*
============================================================================
Name : 47c.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create shared memory and perform the following operations: 
                   c.	Detach the shared memory  

============================================================================
*/

#include <stdio.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    char *data = shmat(shmid, NULL, 0);
    printf("Attached, data: %s\n", data);
    shmdt(data);
    printf("Detached\n");
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 47c
vinaypratap@Ubuntu:~$ cd 47c
vinaypratap@Ubuntu:~/47c$ code .
vinaypratap@Ubuntu:~/47c$ gcc 47c.c -o memory
vinaypratap@Ubuntu:~/47c$ ./memory
Attached, data: hello shared memory
Detached

============================================================================
*/