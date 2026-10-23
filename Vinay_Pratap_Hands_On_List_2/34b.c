/*
============================================================================
Name : 34b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to execute ls -l | wc using:  
                 b.	dup2 


============================================================================
*/

#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        dup2(fd[1], 1);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        dup2(fd[0], 0);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 34b
vinaypratap@Ubuntu:~$ cd 34b
vinaypratap@Ubuntu:~/34b$ code .
vinaypratap@Ubuntu:~/34b$ gcc 34b.c -o dup2
vinaypratap@Ubuntu:~/34b$ ./dup2

Output -
      3      20     132

============================================================================
*/