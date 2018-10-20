#include<stdio.h>
#include<stdlib.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        return 1;//进程创建失败
    }
    else if(pid > 0){
        //父进程 getpid() 调取进程 PID
        printf("parent[%d] is sleeping...\n", getpid());
        sleep(30);
    }
    else{
        printf("child[%d] is begin Z...\n", getpid());
        sleep(5);
        exit(EXIT_SUCCESS);
    }
    return 0;
}
