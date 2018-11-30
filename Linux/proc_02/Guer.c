#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if(pid > 0)
    {
        printf("this is parent process!!!\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("this is child process!!!\n");
    }
    printf("Hello world\n");
    return 0;
}

