/*
============================================================================
Name : 32.c
Author : Vinay Pratap Singh Sirohiya
Description : Develop a simple program to send data from the parent process to the child process. 
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buf[50];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        int n = read(fd[0], buf, sizeof(buf));
        printf("Child received: %.*s", n, buf);
    } else {
        close(fd[0]);
        write(fd[1], "hello from parent\n", 18);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 32
vinaypratap@Ubuntu:~$ cd 32
vinaypratap@Ubuntu:~/32$ code .
vinaypratap@Ubuntu:~/32$ gcc 32.c -o parent
vinaypratap@Ubuntu:~/32$ ./parent

Output -
Child received: hello from parent

============================================================================
*/