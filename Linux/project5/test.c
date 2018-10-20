#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid > 0){
        perror("fork");
        return 1;
    }
    else if(pid == 0){
        printf("child : %d, pid : %d\n", getpid(), pid);
    }
    else{
        printf("father : %d, pid : %d\n", getpid(), pid);
    }
    sleep(1);
    //while(1){
    //    printf("Hello world\n");
    //}
    return 0;
}

