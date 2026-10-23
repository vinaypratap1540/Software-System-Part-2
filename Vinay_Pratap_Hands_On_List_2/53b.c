/*
============================================================================
Name : 53b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs for each time domain to set an interval timer for 10 seconds and 10 microseconds. 
                    b.	Use ITIMER_VIRTUAL  
  
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
    signal(SIGVTALRM, handler);

    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    setitimer(ITIMER_VIRTUAL, &t, NULL);

    while (1);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 53b
vinaypratap@Ubuntu:~$ cd 53b
vinaypratap@Ubuntu:~/53b$ code .
vinaypratap@Ubuntu:~/53b$ gcc 53b.c -o interval
vinaypratap@Ubuntu:~/53b$ ./interval
Timer expired
Timer expired
Timer expired

============================================================================
*/