#include <stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
void handler(int s)
{
    printf("recv %d\n", s);
    //sleep(10);
    //printf("finish\n");
}


int main(void)
{
    struct sigaction act;
    act.sa_handler = handler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);
    struct itimerval tm;
    memset(&tm, 0x00, sizeof tm);
    tm.it_value.tv_sec = 4;
    tm.it_interval.tv_sec = 1;

    setitimer(ITIMER_REAL, &tm, NULL);    

    for( ; ; )
    {
        pause();
    }
}
