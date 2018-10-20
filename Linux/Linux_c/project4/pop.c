#include<stdio.h>
#include<assert.h>
char *Mymemcopy(char *dst, const char *src)
{
    assert(dst != NULL);
    assert(src != NULL);
    char *ret = dst;
    while(*dst = *src){
        dst ++;
        src ++;
    }
    return ret;
}
int main()
{
    char arr1[] = {'1', '2', '3', '4', '5'};
    char arr2[10];
    printf("%s \n", Mymemcopy(arr2, arr1));
    return 0;
}
