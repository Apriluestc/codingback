#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
int g_ticket = 100;
void* y_col(void* arg)
{
    int id = (int)arg;
    while(1)
    {
        //pthread_mutex_lock();
        if(g_ticket > 0)
        {
            usleep(100);
            printf("y_col:%d get a ticket:%d!!\n", id, g_ticket);
            g_ticket--;
        }
        else
        {
            printf("have no ticket!! exit!!\n");
            pthread_exit(NULL);
        }
    }
    return NULL;
}

int main()
{
    pthread_t tid[4];
    int i = 0;
    int ret;
    for(i = 0; i < 4; i++)
    {
        ret = pthread_create(&tid[i], NULL, y_col, (void*)i);
        if(ret != 0)
        {
            printf("pthread_create error\n");
            return -1;
        }
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);
    //printf("Hello world\n");
    return 0;
}
