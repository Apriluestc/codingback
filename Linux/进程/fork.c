#include <stdio.h>
#include <unistd.h>
/*
namespace N
{
    int value = 100;
}
*/
//int value = 100;
int main()
{
    int value = 100;
    pid_t pid = fork();
    if(pid < 0)
    {
        printf("create child process failed!!\n");
        return -1;
    }
    else if(pid == 0)
    {
        //子进程
        printf("this is child!!! %d\n", getpid());
    }
    else
    {
        //父进程
        printf("this is parent!!! %d\n", getpid());
    }
    while(1){
        printf("pid:%d neihoua!!!:%d\n", getpid(), value);
        sleep(1);
    }
    printf("Hello world\n");
    return 0;
}

