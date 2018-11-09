#include <iostream>
using namespace std;
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int pipefd[2];
    if(pipe(pipefd) < 0)
    {
        perror("pipe error");
        return -1;
    }
    int pid = fork();
    if(pid < 0)
    {
        return -1;
    }
    else if(pid == 0)
    {
        //child
        //grep ssh
        
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        execlp("grep", "grep", "ssh", NULL);
        close(pipefd[0]);
    }
    else
    {
        
        close(pipefd[0]);
        //parent
        dup2(pipefd[1], 1);
        execlp("ps", "ps", "-ef", NULL);
        close(pipefd[1]);
    }
    //std::cout << "Hello world" << std::endl;
    return 0;
}

