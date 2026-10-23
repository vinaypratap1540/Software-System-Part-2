/*
============================================================================
Name : 46.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to remove the message queue.    

============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

int main() {
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_RMID, NULL);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 46
vinaypratap@Ubuntu:~$ cd 46
vinaypratap@Ubuntu:~/46$ code .
vinaypratap@Ubuntu:~/46$ gcc 46.c -o queue
vinaypratap@Ubuntu:~/46$ ./queue

============================================================================
*/