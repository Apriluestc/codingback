#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    int ret = fork();
    if(ret < 0){    //创建进程失败
        perror("fork");
        return 1;
    }
    else if(ret == 0){  //子进程
        printf("I an child : %d!, ret: %d\n", getpid(), ret);
    }
    else{   //父进程
        printf("I an father : %d!, ret: %d\n", getpid(), ret);
    }
    return 0;
}
