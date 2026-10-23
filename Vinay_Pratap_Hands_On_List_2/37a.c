/*
============================================================================
Name : 37a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write two programs to enable communication through FIFO using one-way communication. 
 

============================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("files/fifo37", 0644);
    int fd = open("files/fifo37", O_WRONLY);
    write(fd, "hello through fifo\n", 19);
    close(fd);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 37a
vinaypratap@Ubuntu:~$ cd 37a
vinaypratap@Ubuntu:~/37a$ code .
vinaypratap@Ubuntu:~/37a$ gcc 37a.c -o fifo
vinaypratap@Ubuntu:~/37a$ ./fifo

============================================================================
*/c