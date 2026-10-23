/*
============================================================================
Name : 59g.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the signal system call to catch the following signals: 
               g.	SIGPROF (using the setitimer system call)    
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGPROF\n");
    _exit(0);
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGPROF, handler);
    setitimer(ITIMER_PROF, &t, NULL);
    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 59g
vinaypratap@Ubuntu:~$ cd 59g
vinaypratap@Ubuntu:~/59g$ code .
vinaypratap@Ubuntu:~/59g$ gcc 59g.c -o sigprof
vinaypratap@Ubuntu:~/59g$ ./sigprof
Caught SIGPROF
============================================================================
*/