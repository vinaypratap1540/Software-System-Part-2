/*
============================================================================
Name : 34a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to execute ls -l | wc using: 
               a. dup 

============================================================================
*/

#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(0);
        dup(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 34a
vinaypratap@Ubuntu:~$ cd 34a
vinaypratap@Ubuntu:~/34a$ code .
vinaypratap@Ubuntu:~/34a$ gcc 34a.c -o dup
vinaypratap@Ubuntu:~/34a$ ./dup

Output - 
      3      20     131

============================================================================
*/