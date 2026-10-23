/*
============================================================================
Name : 41.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create a message queue, and print the key and message queue ID. 
============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0644);
    printf("Key: 0x%x\nMessage queue id: %d\n", key, msqid);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 41
vinaypratap@Ubuntu:~$ cd 41
vinaypratap@Ubuntu:~/41$ code .
vinaypratap@Ubuntu:~/41$ gcc 41.c -o queue
vinaypratap@Ubuntu:~/41$ ./queue

Key: 0x61020a22
Message queue id: 0

============================================================================
*/