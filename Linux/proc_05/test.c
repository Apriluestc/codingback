#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

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
        sleep(20);
        exit(0);
        //printf("This is child process!!! [%d]\n", getpid());
        //while(time--)
            //exit(0);
    }
    else
    {
        int st;
        int ret = wait(&st);
        if(ret > 0 && (st & 0X7f) == 0)
        {
            printf("child exit code:%d\n", (st>>8)&0X7F);
            
        }
        else if(ret > 0)
        {
            printf("sig code:%d\n", st&0X7F);
        }
        //while(time--)
        //{
        //printf("I am going to become zombie!!\n");
        //sleep(1);
        //printf("This is parent process!!! [%d]\n", getpid());
    
        //}
    }
    /*
    while(1)
    {
        sleep(1);
        printf("This is public!!! [%d]\n", getpid());
    }
    printf("Hello world\n");
    return 0;
    */
}

