#include <stdio.h>
#include <unistd.h>
int g_val = 100;
int main()
{
    int val = 50;
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if(pid == 0)
    {
        printf("pid:%d I am child process!!!!\n", getpid());
    }
    else
    {
        printf("pid:%d I am parent process!!!!\n", getpid());
    }
    while(1)
    {
        printf("pid:%d neihua!!! public %d %d\n", getpid(), g_val, val);
        sleep(1);
    }
    //printf("Hello world\n");
    return 0;
}

