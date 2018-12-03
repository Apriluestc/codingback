#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork\n");
        return -1;
    }
    else if(pid == 0)
    {
        setpgid(pid, 0);
        printf("I am child process!!!\n");
    }
    else
    {
        printf("I am parent process!!!\n");
    }
    printf("Hello world\n");
    return 0;
}

