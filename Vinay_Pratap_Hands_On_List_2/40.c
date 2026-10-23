/*
============================================================================
Name : 40.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to print the maximum number of files that can be opened within a process and the size of a pipe (circular buffer). 
============================================================================
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Pipe size: %d\n", fcntl(fd[0], F_GETPIPE_SZ));
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 40
vinaypratap@Ubuntu:~$ cd 40
vinaypratap@Ubuntu:~/40$ code .
vinaypratap@Ubuntu:~/40$ gcc 40.c -o pipe
vinaypratap@Ubuntu:~/40$ ./pipe

Max open files: 524288
Pipe size: 65536

============================================================================
*/