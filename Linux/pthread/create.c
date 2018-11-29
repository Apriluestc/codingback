#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>
#include <errno.h>
#include <string.h>
void* thr_start(void* arg)
{
    //printf("I am pthread:\n");
    int num = (int)arg;
    while(1)
    {
        printf("I am pthread:talk with girl friend!!!\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t tid;  //接收用户线程 ID 
    int ret;
    ret = pthread_create(&tid, NULL, thr_start, (void*)999);    //创建
    if(ret != 0)
    {
        perror("pthread_create errno");
        return -1;
    }
    int i;
    while(1)
    {
        printf("--------------line--------------\n");
        printf("I am main pthread:play game!!!\n");
        sleep(1);
    }
    //printf("Hello world\n");
    //return 0;
}

