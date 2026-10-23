/*
============================================================================
Name : 31.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a simple program to create a pipe, write to the pipe, read from the pipe, and display the content on the monitor.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buf[50];
    pipe(fd);
    write(fd[1], "hello through pipe\n", 19);
    int n = read(fd[0], buf, sizeof(buf));
    write(1, buf, n);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 31
vinaypratap@Ubuntu:~$ cd 31 
vinaypratap@Ubuntu:~/31$ code .
vinaypratap@Ubuntu:~/31$ gcc 31.c -o pipe
vinaypratap@Ubuntu:~/31$ ./pipe

Output - hello through pipe

============================================================================
*/