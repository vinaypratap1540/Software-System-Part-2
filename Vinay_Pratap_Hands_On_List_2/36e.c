/*
============================================================================
Name : 36e.c
Author : Vinay Pratap Singh Sirohiya
Description : Create a FIFO file using: 
                e.	mkfifo library Function
 

============================================================================
*/

#include <sys/stat.h>

int main() {
    mkfifo("files/fifo36e", 0644);
    return 0;
}

/*
============================================================================
Sample Output : 
---------------------------------------------------------------------------- 
vinaypratap@Ubuntu:~$ mkdir 36e
vinaypratap@Ubuntu:~$ cd 36e
vinaypratap@Ubuntu:~/36e$ code .
vinaypratap@Ubuntu:~/36e$ gcc 36e.c -o mkfifo
vinaypratap@Ubuntu:~/36e$ ./mkfifo

============================================================================
*/