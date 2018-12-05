#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int pid = -1;
    pid = fork();
    if(pid < 0)
        exit(-1);
    else if(pid == 0)
    {
        sleep(10);
        exit(0);
    }
    waitpid(-1, NULL, 0);
    while(1)
    {
        printf("wait snow!!!\n");
        sleep(1);
    }
    printf("Hello world\n");
    return 0;
}

