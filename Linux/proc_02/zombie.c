#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if(pid > 0)
    {
        printf("parent[%d] is sleeping ···\n", getpid());
        sleep(30);
    }
    else
    {
        int i = 10;
        while(i--)
        {
            //printf("[%d] seconds later will become zombie···\n", i);
            printf("child[%d] is begin Z···\n", getpid());
            exit(EXIT_SUCCESS);
        }
        printf("[%d] seconds later will become zombie···\n", i);
    }
    printf("Hello world\n");
    return 0;
}

