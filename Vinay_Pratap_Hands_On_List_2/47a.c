/*
============================================================================
Name : 47a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create shared memory and perform the following operations: 
                 a.	Write some data to the shared memory 
    

============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, IPC_CREAT | 0644);
    char *data = shmat(shmid, NULL, 0);
    strcpy(data, "hello shared memory");
    printf("Written: %s\n", data);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 47a
vinaypratap@Ubuntu:~$ cd 47a
vinaypratap@Ubuntu:~/47a$ code .
vinaypratap@Ubuntu:~/47a$ gcc 47a.c -o memory
vinaypratap@Ubuntu:~/47a$ ./memory
Written: hello shared memory

============================================================================
*/