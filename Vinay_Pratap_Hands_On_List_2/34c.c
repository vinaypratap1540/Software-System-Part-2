/*
============================================================================
Name : 34c.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to execute ls -l | wc using: 
                c.	fcntl 


============================================================================
*/

#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(1);
        fcntl(fd[1], F_DUPFD, 1);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(0);
        fcntl(fd[0], F_DUPFD, 0);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 34c
vinaypratap@Ubuntu:~$ cd 34c
vinaypratap@Ubuntu:~/34c$ code .
vinaypratap@Ubuntu:~/34c$ gcc 34c.c -o fcntl
vinaypratap@Ubuntu:~/34c$ ./fcntl

Output - 
      3      20     133

============================================================================
*/