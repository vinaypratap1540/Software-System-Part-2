/*
============================================================================
Name : 59e.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the signal system call to catch the following signals: 
               e.	SIGALRM (using the setitimer system call)   
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGALRM (setitimer)\n");
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGALRM, handler);
    setitimer(ITIMER_REAL, &t, NULL);
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 59e
vinaypratap@Ubuntu:~$ cd 59e
vinaypratap@Ubuntu:~/59e$ code .
vinaypratap@Ubuntu:~/59e$ gcc 59e.c -o sigalarm
vinaypratap@Ubuntu:~/59e$ ./sigalarm
Caught SIGALRM (setitimer)
============================================================================
*/