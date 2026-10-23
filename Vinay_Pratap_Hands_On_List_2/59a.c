/*
============================================================================
Name : 59a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the signal system call to catch the following signals: 
               a.	SIGSEGV 
  
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSEGV\n");
    _exit(1);
}

int main() {
    signal(SIGSEGV, handler);
    int *p = NULL;
    *p = 10;
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 59a
vinaypratap@Ubuntu:~$ cd 59a
vinaypratap@Ubuntu:~/59a$ code .
vinaypratap@Ubuntu:~/59a$ gcc 59a.c -o signal
vinaypratap@Ubuntu:~/59a$ ./signal
Caught SIGSEGV
============================================================================
*/