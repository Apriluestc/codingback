#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
int main()
{
    int time = 10;
    int pid = -1;
    pid = vfork();
    if(pid < 0)
    {
        perror("vfork");
        exit(0);
    }
    else if(pid == 0)
    {
        printf("This is child process!!! [%d]\n", getpid());
        while(time--)
            exit(0);
    }
    else
    {
        while(time--)
        {
            sleep(1);
            printf("This is parent process!!! [%d]\n", getpid());
    
        }
    }
    while(1)
    {
        sleep(1);
        printf("This is public!!! [%d]\n", getpid());
    }
    printf("Hello world\n");
    return 0;
}

