/*
============================================================================
Name : 37b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write two programs to enable communication through FIFO using one-way communication. 
 

============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char buf[50];
    mkfifo("files/fifo37", 0644);
    int fd = open("files/fifo37", O_RDONLY);
    int n = read(fd, buf, sizeof(buf));
    printf("Received: %.*s", n, buf);
    close(fd);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 37b
vinaypratap@Ubuntu:~$ cd 37b
vinaypratap@Ubuntu:~/37b$ code .
vinaypratap@Ubuntu:~/37b$ gcc 37b.c -o fifo
vinaypratap@Ubuntu:~/37b$ ./fifo
Received: vinaypratap@Ubuntu:~/37b$ 

============================================================================
*/