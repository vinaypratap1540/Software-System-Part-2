/*
============================================================================
Name : 53c.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs for each time domain to set an interval timer for 10 seconds and 10 microseconds. 
                    c.	Use ITIMER_PROF   
  
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
    signal(SIGPROF, handler);

    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    setitimer(ITIMER_PROF, &t, NULL);

    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 53c
vinaypratap@Ubuntu:~$ cd 53c
vinaypratap@Ubuntu:~/53c$ code .
vinaypratap@Ubuntu:~/53c$ gcc 53c.c -o interval
vinaypratap@Ubuntu:~/53c$ ./interval
Timer expired
Timer expired
Timer expired
Timer expired
============================================================================
*/