#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

void mydemon(void)
{
    int i;
    int fd0;
    pid_t pid;
    struct sigaction sa;

    umask(0);   //1、调用 umask k将文件模式创建屏蔽字设置为 0
    //调用 fork 父进程退出
    if((pid = fork()) < 0)
    {
        perror("fork\n");
        return;
    }
    else if((pid = fork()) > 0)
    {
        exit(0);
    }
    setsid();   //创建一个新会话
    sa.sa_handler = SIG_IGN; //忽略 SIGCHLD 信号
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if(sigaction(SIGCHLD, &sa, NULL) < 0)
    {
        return ;//注册子进程退出忽略信号
    }
    //注意：再次 fork ，终止父进程，保持子进程不是会话首进程从而保证后续不再会跟其他终端关联
    if((pid = fork()) < 0)
    {
        perror("fork");
        return ;
    }
    if((pid = fork()) > 0)
    {
        exit(0);
    }
    if(chdir("/") < 0)
    {
        printf("chdir error\n");
        return ;
    }
    //文件重定向
    close(0);
    fd0 = open("dev/null", O_RDWR);
    dup2(fd0, 1);
    dup2(fd0, 2);

}

int main()
{
    mydemon();
    while(1)
    {
        sleep(1);
    }
    //printf("Hello world\n");
    //return 0;
}

