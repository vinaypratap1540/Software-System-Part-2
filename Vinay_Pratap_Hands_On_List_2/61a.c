/*
============================================================================
Name : 61a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the sigaction system call to catch the following signals: 
                a.	SIGSEGV 
     
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSEGV\n");
    _exit(1);
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 10;
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 61a
vinaypratap@Ubuntu:~$ cd 61a
vinaypratap@Ubuntu:~/61a$ code .
vinaypratap@Ubuntu:~/61a$ gcc 61a.c -o sigaction
vinaypratap@Ubuntu:~/61a$ ./sigaction
Caught SIGSEGV
============================================================================
*/