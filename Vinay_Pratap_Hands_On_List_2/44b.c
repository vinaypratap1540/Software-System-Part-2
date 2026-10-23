/*
============================================================================
Name : 44a.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to receive messages from the message queue: 
                b.	With IPC_NOWAIT as a flag  

============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[50];
};

int main() {
    struct msg m;
    int msqid = msgget(ftok(".", 'a'), 0);
    if (msgrcv(msqid, &m, sizeof(m.text), 0, IPC_NOWAIT) == -1)
        printf("No message in queue\n");
    else
        printf("Received (type %ld): %s\n", m.type, m.text);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 44b
vinaypratap@Ubuntu:~$ cd 44b
vinaypratap@Ubuntu:~/44b$ code .
vinaypratap@Ubuntu:~/44b$ gcc 44b.c -o queue
vinaypratap@Ubuntu:~/44b$ ./queue
No message in queue

============================================================================
*/