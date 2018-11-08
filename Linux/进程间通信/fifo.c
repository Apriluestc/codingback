#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    umask(0);
    //创建命名管道
    if(mkfifo("./test.fifo", 0664) < 0){
        if(errno == EEXIST){
            //代表文件已经存在
        }
        else{    
            perror("mkfifo error");
            return -1;
    
        }
    }
    //打开管道文件
    //打开特性:如果以只读打开命名管道,那么open函数将阻塞等待
    //知道有其他进程以写的方式打开这个,命名管道
    //如果以只写打开命名管道,那么open函数将阻塞等待
    //直到有其他进程以度的方式打开这个命名管道
    //
    //如果命名管道以读写方式打开将不会阻塞
    int fd = open("./test.fifo", O_RDONLY);
    if(fd < 0){
        perror("open fifo error");
        return -1;
    }
    printf("open fifo file success!! read start!!\n");
    while(1){
        char buffer[1024] = {0};
        read(fd, buffer, 1023);
        printf("client say:[%s]\n", buffer);
    }
    close(fd);
    printf("Hello world\n");
    return 0;
}

