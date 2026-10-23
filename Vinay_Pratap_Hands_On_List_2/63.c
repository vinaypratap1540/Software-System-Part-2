/*
============================================================================
Name : 63.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create an orphan process. 
Utilize the kill system call to send a SIGKILL signal from the child process to the parent process.  
     
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Child %d, parent before kill: %d\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        sleep(1);
        printf("Child %d, parent after kill: %d\n", getpid(), getppid());
    } else {
        printf("Parent %d sleeping\n", getpid());
        sleep(10);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 63
vinaypratap@Ubuntu:~$ cd 63
vinaypratap@Ubuntu:~/63$ code .
vinaypratap@Ubuntu:~/63$ gcc 63.c -o sigkill
vinaypratap@Ubuntu:~/63$ ./sigkill
Parent 16230 sleeping
Child 16231, parent before kill: 16230
Killed                     ./sigkill
vinaypratap@Ubuntu:~/63$ Child 16231, parent after kill: 2815
============================================================================
*/