//这是一个匿名管道的实现，功能：父进程写入数据，子进程读取数据打印
//int pipe(int pipefd[2]);
//pipefd:用于接收匿名管道创建成功后返回两个描述符
//pipefd[1]用于写入数据
//pipefd[0]用于读取数据
//返回值：
//  0    成功   -1  失败
#include<iostream>
using namespace std;
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
int main()
{
    int fd[2];
    //管道需要在创建子进程之前创建好，这样才能复制
    if(pipe(fd) < 0)
    {
        perror("pipe error");
        return -1;
    }
    int pid = -1;
    pid = fork();
    if(pid < 0)
    {
        return -1;
    }
    else if(pid == 0)
    {
        close(fd[1]);
        char buffer[1024] = {0};
        read(fd[0], buffer, 1024);//如果管道中没有数据则会阻塞等待
        cout<<"child:"<<buffer<<endl;
        close(fd[0]);
        //child read
    }
    else 
    {
        sleep(3);
        close(fd[0]);
        write(fd[1], "hello", 5);
        close(fd[1]);
        //parent write
    }
    //std::cout << "Hello world" << std::endl;
    return 0;
}

