/*
============================================================================
Name : 57.c
Author : Vinay Pratap Singh Sirohiya
Description : Write a program to print system limitations for: 
a.	Maximum length of arguments in the exec family of functions. 
b.	Maximum number of simultaneous processes per user ID. 
c.	Number of clock ticks (jiffies) per second. 
d.	Maximum number of open files. 
e.	Size of a page. 
f.	Total number of pages in physical memory. 
g.	Number of currently available pages in physical memory. 
    
  
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Max length of exec arguments: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Max processes per user: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Page size: %ld\n", sysconf(_SC_PAGESIZE));
    printf("Total physical pages: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Available physical pages: %ld\n", sysconf(_SC_AVPHYS_PAGES));
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 57
vinaypratap@Ubuntu:~$ cd 57
vinaypratap@Ubuntu:~/57$ code .
vinaypratap@Ubuntu:~/57$ gcc 57.c -o limitations
vinaypratap@Ubuntu:~/57$ ./limitations
Max length of exec arguments: 2097152
Max processes per user: 10155
Clock ticks per second: 100
Max open files: 524288
Page size: 4096
Total physical pages: 1145376
Available physical pages: 181760
============================================================================
*/