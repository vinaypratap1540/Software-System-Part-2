/*
============================================================================
Name : 38a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write two programs to establish communication through FIFO using two-way communication. 

============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char buf[50];
    mkfifo("files/fifo38_1", 0644);
    mkfifo("files/fifo38_2", 0644);
    int wfd = open("files/fifo38_1", O_WRONLY);
    int rfd = open("files/fifo38_2", O_RDONLY);

    write(wfd, "hello from 38a\n", 15);
    int n = read(rfd, buf, sizeof(buf));
    printf("38a received: %.*s", n, buf);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 38a
vinaypratap@Ubuntu:~$ cd 38a
vinaypratap@Ubuntu:~/38a$ code .
vinaypratap@Ubuntu:~/38a$ gcc 38a.c -o fifo
vinaypratap@Ubuntu:~/38a$ ./fifo
38a received:

============================================================================
*/