/*
============================================================================
Name : 59b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the signal system call to catch the following signals: 
               b.	SIGINT 
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT\n");
}

int main() {
    signal(SIGINT, handler);
    printf("Press Ctrl+C\n");
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 59b
vinaypratap@Ubuntu:~$ cd 59b
vinaypratap@Ubuntu:~/59b$ code .
vinaypratap@Ubuntu:~/59b$ gcc 59b.c -o signal
vinaypratap@Ubuntu:~/59b$ ./signal
Press Ctrl+C
^CCaught SIGINT
============================================================================
*/