/*
============================================================================
Name : 51b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to communicate between two machines using sockets.    

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    char buf[100];
    struct sockaddr_in addr;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(8080);

    connect(sfd, (struct sockaddr *)&addr, sizeof(addr));
    write(sfd, "hello from client\n", 18);
    int n = read(sfd, buf, sizeof(buf));
    printf("Server says: %.*s", n, buf);

    close(sfd);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 51b
vinaypratap@Ubuntu:~$ cd 51b
vinaypratap@Ubuntu:~/51b$ code .
vinaypratap@Ubuntu:~/51b$ gcc 51b.c -o socket
vinaypratap@Ubuntu:~/51b$ ./socket 127.0.0.1
Server says: hello from server
============================================================================
*/
