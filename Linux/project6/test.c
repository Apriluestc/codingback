#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        return 1;
    }
    else if(pid == 0){
        printf("child: pid : %d\n", getpid());
        sleep(10);
    }
    else{
        printf("father: pid : %d\n", getpid());
        sleep(3);
        exit(0);
    }
    return 0;
}
