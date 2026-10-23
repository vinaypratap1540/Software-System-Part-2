/*
============================================================================
Name : 61c.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the sigaction system call to catch the following signals: 
                c.	SIGFPE  
     
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGFPE\n");
    _exit(1);
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGFPE, &sa, NULL);

    int a = 10, b = 0;
    printf("%d\n", a / b);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 61c
vinaypratap@Ubuntu:~$ cd 61c
vinaypratap@Ubuntu:~/61c$ code .
vinaypratap@Ubuntu:~/61c$ gcc 61c.c -o sigfpe
vinaypratap@Ubuntu:~/61c$ ./sigfpe
Caught SIGFPE
============================================================================
*/