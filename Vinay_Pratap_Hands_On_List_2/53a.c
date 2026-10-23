/*
============================================================================
Name : 53a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs for each time domain to set an interval timer for 10 seconds and 10 microseconds. 
                    a.	Use ITIMER_REAL 
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Timer expired\n");
}

int main() {
    struct itimerval t;
    signal(SIGALRM, handler);

    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    setitimer(ITIMER_REAL, &t, NULL);

    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 53a
vinaypratap@Ubuntu:~$ cd 53a
vinaypratap@Ubuntu:~/53a$ code .
vinaypratap@Ubuntu:~/53a$ gcc 53a.c -o interval
vinaypratap@Ubuntu:~/53a$ ./interval
Timer expired
Timer expired
Timer expired
Timer expired

============================================================================
*/