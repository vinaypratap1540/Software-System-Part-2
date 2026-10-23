/*
============================================================================
Name : 56.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to measure the time taken to execute 100 getppid() system calls using a time stamp counter.    
  
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>

int main() {
    unsigned long long start = __rdtsc();
    for (int i = 0; i < 100; i++)
        getppid();
    unsigned long long end = __rdtsc();
    printf("Cycles for 100 getppid(): %llu\n", end - start);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 56
vinaypratap@Ubuntu:~$ cd 56
vinaypratap@Ubuntu:~/56$ code .
vinaypratap@Ubuntu:~/55/56$ gcc 56.c -o timecal
vinaypratap@Ubuntu:~/55/56$ ./timecal
Cycles for 100 getppid(): 32827
============================================================================
*/