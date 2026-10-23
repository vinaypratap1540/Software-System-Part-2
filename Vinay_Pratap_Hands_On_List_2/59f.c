/*
============================================================================
Name : 59f.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the signal system call to catch the following signals: 
               f.	SIGVTALRM (using the setitimer system call)   
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGVTALRM\n");
    _exit(0);
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGVTALRM, handler);
    setitimer(ITIMER_VIRTUAL, &t, NULL);
    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 59f
vinaypratap@Ubuntu:~$ cd 59f
vinaypratap@Ubuntu:~/59f$ code .
vinaypratap@Ubuntu:~/59f$ gcc 59f.c -o sigvtalrm
vinaypratap@Ubuntu:~/59f$ ./sigvtalrm
Caught SIGVTALRM
============================================================================
*/