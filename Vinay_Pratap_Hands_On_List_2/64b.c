/*
============================================================================
Name : 64b.c
Author : Vinay Pratap Singh Sirohiya
Description : Create two programs: the first program awaits the SIGSTOP signal, 
while the second program sends the signal using the kill system call. 
Determine whether the first program successfully catches the signal or not.   
     
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    kill(atoi(argv[1]), SIGSTOP);
    printf("Sent SIGSTOP to %s\n", argv[1]);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 64b
vinaypratap@Ubuntu:~$ cd 64b
vinaypratap@Ubuntu:~/64b$ code .
vinaypratap@Ubuntu:~/64b$ gcc 64b.c -o kill
vinaypratap@Ubuntu:~/64b$ ./kill
Sent SIGSTOP to 16789
============================================================================
*/