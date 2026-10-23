/*
============================================================================
Name : 38b.c
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
    int rfd = open("files/fifo38_1", O_RDONLY);
    int wfd = open("files/fifo38_2", O_WRONLY);

    int n = read(rfd, buf, sizeof(buf));
    printf("38b received: %.*s", n, buf);
    write(wfd, "hello from 38b\n", 15);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 38b
vinaypratap@Ubuntu:~$ cd 38b
vinaypratap@Ubuntu:~/38b$ code .
vinaypratap@Ubuntu:~/38b$ gcc 38b.c -o fifo
vinaypratap@Ubuntu:~/38b$ ./fifo
38b received:

============================================================================
*/