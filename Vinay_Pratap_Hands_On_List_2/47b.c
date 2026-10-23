/*
============================================================================
Name : 47b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create shared memory and perform the following operations: 
                   b.	Attach with O_RDONLY and check whether you are able to overwrite 

============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    char *data = shmat(shmid, NULL, SHM_RDONLY);
    printf("Read: %s\n", data);
    printf("Trying to overwrite...\n");
    fflush(stdout);
    strcpy(data, "overwrite");
    printf("Overwritten: %s\n", data);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 47b
vinaypratap@Ubuntu:~$ cd 47b
vinaypratap@Ubuntu:~/47b$ code .
vinaypratap@Ubuntu:~/47b$ gcc 47b.c -o memory
vinaypratap@Ubuntu:~/47b$ ./memory
Segmentation fault         (core dumped) ./memory

============================================================================
*/