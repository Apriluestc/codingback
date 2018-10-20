#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    printf("pit: %d\n", getpid()); //PID 进程ID
    printf("ppid: %d\n", getppid()); // 父进程ID
    return 0;
}
