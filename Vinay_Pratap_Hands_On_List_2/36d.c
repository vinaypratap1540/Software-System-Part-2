/*
============================================================================
Name : 36d.c
Author : Vinay Pratap Singh Sirohiya
Description : Create a FIFO file using: 
                d.	mknod System Call
 

============================================================================
*/

#include <sys/stat.h>

int main() {
    mknod("files/fifo36d", S_IFIFO | 0644, 0);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 36d
vinaypratap@Ubuntu:~$ cd 36d
vinaypratap@Ubuntu:~/36d$ code .
vinaypratap@Ubuntu:~/36d$ gcc 36d.c -o mknod
vinaypratap@Ubuntu:~/36d$ ./mknod

============================================================================
*/