/*
============================================================================
Name : 59c.c
Author : Vinay Pratap Singh Sirohiya
Description : Write separate programs using the signal system call to catch the following signals: 
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
    signal(SIGFPE, handler);
    int a = 10, b = 0;
    printf("%d\n", a / b);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 59c
vinaypratap@Ubuntu:~$ cd 59c
vinaypratap@Ubuntu:~/59c$ code .
vinaypratap@Ubuntu:~/59c$ gcc 59c.c -o signal
vinaypratap@Ubuntu:~/59c$ ./signal
Caught SIGFPE
============================================================================
*/