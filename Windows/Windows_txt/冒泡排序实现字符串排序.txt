#include <stdio.h>
#include <string.h>

void bubble_sort_str(char *str[],int sz)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < sz - 1; i++)
    {
        for (j = 0; j < sz - 1 - i; j++)
        {
             if (strcmp(*(str + j), *(str + j + 1))>0)
             {
                 char *tmp = *(str+j);
                 *(str + j) = *(str + j + 1);
                 *(str + j + 1) = tmp;
             }
        }
    }
}
int main()
{
    int i = 0;
    char *str[] = { "aacc", "bbbb", "dddd", "aaaa" };
    bubble_sort_str(str,sizeof(str)/sizeof(*str));
    for (i = 0; i < sizeof(str) / sizeof(str[1]); i++)
    {
        printf("%s ", *(str+i));
    }
    printf("\n");
    return 0;
}