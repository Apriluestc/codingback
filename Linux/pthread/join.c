#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int main()
{
    void** ptr;
    pthread_join(tid, (void**)ptr);

    //printf("Hello world\n");
    //return 0;
}

