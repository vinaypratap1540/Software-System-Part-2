/*
============================================================================
Name : 64a.c
Author : Vinay Pratap Singh Sirohiya
Description : Create two programs: the first program awaits the SIGSTOP signal, 
while the second program sends the signal using the kill system call. 
Determine whether the first program successfully catches the signal or not.   
     
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSTOP\n");
}

int main() {
    if (signal(SIGSTOP, handler) == SIG_ERR)
        printf("Cannot set handler for SIGSTOP\n");
    printf("pid %d waiting for SIGSTOP\n", getpid());
    while (1)
        sleep(1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 64a
vinaypratap@Ubuntu:~$ cd 64a
vinaypratap@Ubuntu:~/64a$ code .
vinaypratap@Ubuntu:~/64a$ gcc 64a.c -o sigstop
vinaypratap@Ubuntu:~/64a$ ./sigstop
Cannot set handler for SIGSTOP
pid 16789 waiting for SIGSTOP
============================================================================
*/