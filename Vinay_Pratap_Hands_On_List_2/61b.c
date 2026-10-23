/*
============================================================================
Name : 61b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the sigaction system call to catch the following signals: 
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
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C\n");
    pause();
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 61b
vinaypratap@Ubuntu:~$ cd 61b
vinaypratap@Ubuntu:~/61b$ code .
vinaypratap@Ubuntu:~/61b$ gcc 61b.c -o sigint
vinaypratap@Ubuntu:~/61b$ ./sigint
Press Ctrl+C
^CCaught SIGINT
============================================================================
*/