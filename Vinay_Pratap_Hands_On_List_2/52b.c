/*
============================================================================
Name : 52b.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to create a concurrent server: 
               b.	Use pthread_create  
    

============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>

void *handle(void *arg) {
    char buf[100];
    int cfd = (long)arg;
    int n = read(cfd, buf, sizeof(buf));
    printf("Thread %lu got: %.*s", pthread_self(), n, buf);
    write(cfd, "hello from server\n", 18);
    close(cfd);
    return NULL;
}

int main() {
    struct sockaddr_in addr;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(sfd, (struct sockaddr *)&addr, sizeof(addr));
    listen(sfd, 5);
    printf("Concurrent server (pthread) on port 8080\n");

    while (1) {
        int cfd = accept(sfd, NULL, NULL);
        pthread_t t;
        pthread_create(&t, NULL, handle, (void *)(long)cfd);
        pthread_detach(t);
    }
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 52b
vinaypratap@Ubuntu:~$ cd 52b
vinaypratap@Ubuntu:~/52b$ code .
vinaypratap@Ubuntu:~/52b$ gcc 52b.c -o pthread
vinaypratap@Ubuntu:~/52b$ ./pthread
Concurrent server (pthread) on port 8080

============================================================================
*/