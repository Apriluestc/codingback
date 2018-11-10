#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        return -1;
    }
    else if(pid == 0)
    {
        printf("This is child:");
    }
    else
    {
        printf("This is parent:");
    }
    printf("Hello world\n");
    return 0;
}

