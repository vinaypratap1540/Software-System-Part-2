/*
============================================================================
Name : 42.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to print information about a message queue using msqid_ds and ipc_perm structures: 
a.	Access permission 
b.	UID, GID 
c.	Time of last message sent and received 
d.	Time of last change in the message queue 
e.	Size of the queue 
f.	Number of messages in the queue 
g.	Maximum number of bytes allowed 
h.	PID of the msgsnd and msgrcv 

============================================================================
*/

#include <stdio.h>
#include <time.h>
#include <sys/msg.h>

int main() {
    struct msqid_ds ds;
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_STAT, &ds);

    printf("Access permission: %o\n", ds.msg_perm.mode);
    printf("UID: %d, GID: %d\n", ds.msg_perm.uid, ds.msg_perm.gid);
    printf("Last msg sent: %s", ctime(&ds.msg_stime));
    printf("Last msg received: %s", ctime(&ds.msg_rtime));
    printf("Last change: %s", ctime(&ds.msg_ctime));
    printf("Current size of queue (bytes): %lu\n", ds.__msg_cbytes);
    printf("Number of messages: %lu\n", ds.msg_qnum);
    printf("Max bytes allowed: %lu\n", ds.msg_qbytes);
    printf("PID of last msgsnd: %d, msgrcv: %d\n", ds.msg_lspid, ds.msg_lrpid);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 42
vinaypratap@Ubuntu:~$ cd 42
vinaypratap@Ubuntu:~/42$ code .
vinaypratap@Ubuntu:~/42$ gcc 42.c -o information
vinaypratap@Ubuntu:~/42$ ./information
Access permission: 0
UID: 0, GID: 10420224
Last msg sent: Thu Jan  1 13:39:12 1970
Last msg received: Sat May 26 00:54:48 4461240
Last change: Wed Dec 27 03:37:42 27284
Current size of queue (bytes): 0
Number of messages: 0
Max bytes allowed: 0
PID of last msgsnd: 0, msgrcv: 0

============================================================================
*/