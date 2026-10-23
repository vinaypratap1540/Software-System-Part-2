/*
============================================================================
Name : 58.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a simple program to create three threads and print the IDs of the created threads.  
    
  
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void *run(void *arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t t[3];
    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, run, NULL);
    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 58
vinaypratap@Ubuntu:~$ cd 58
vinaypratap@Ubuntu:~/58$ code .
vinaypratap@Ubuntu:~/58$ gcc 58.c -o multithread
vinaypratap@Ubuntu:~/58$ ./multithread
Thread ID: 138962958022336
Thread ID: 138962941236928
Thread ID: 138962949629632
============================================================================
*/