/*
============================================================================
Name : 59d.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the signal system call to catch the following signals: 
               d.	SIGALRM (using the alarm system call)  
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM (alarm)\n");
}

int main() {
    signal(SIGALRM, handler);
    alarm(2);
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 59d
vinaypratap@Ubuntu:~$ cd 59d
vinaypratap@Ubuntu:~/59d$ code .
vinaypratap@Ubuntu:~/59d$ gcc 59d.c -o sigalarm
vinaypratap@Ubuntu:~/59d$ ./sigalarm
Caught SIGALRM (alarm)
============================================================================
*/