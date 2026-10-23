/*
============================================================================
Name : 43.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to send messages to the message queue. Check using $ipcs -q.
============================================================================
*/

#include <string.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[50];
};

int main() {
    struct msg m;
    int msqid = msgget(ftok(".", 'a'), 0);

    m.type = 1;
    strcpy(m.text, "first message");
    msgsnd(msqid, &m, strlen(m.text) + 1, 0);

    m.type = 2;
    strcpy(m.text, "second message");
    msgsnd(msqid, &m, strlen(m.text) + 1, 0);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 43
vinaypratap@Ubuntu:~$ cd 43
vinaypratap@Ubuntu:~/43$ code .
vinaypratap@Ubuntu:~/43$ gcc 43.c -o ipcs
vinaypratap@Ubuntu:~/43$ ./ipcs

============================================================================
*/