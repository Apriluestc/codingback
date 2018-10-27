#include <stdio.h>
/*
 //在字符串 str1 中查找字符串 str2 出现的位置并返回一个指针
 */
char* my_strstr(char const* str1, char const* str2)
{
    register char* last;
    register char* current;
    /*
    把指针初始化成我们已经找到的前一次匹配的位置.
    */
    last = NULL;
    /*
     只在第二个字符串 str2 不为空时查找
     */
    if(*str2 != '\0')
    {
        current = strstr(str1, str2);
        /*
        我们每次找到字符串时, 让指针指向它的起始位置.然后查找该字符串下一个匹配的位置.
        */
        while(current != NULL)
        {
            last = current;
            current = strstr(last + 1, str2);
        }
    }
    return last;    //返回指向我们最后一次匹配到起始位置的指针
}
int main()
{
    printf("Hello world\n");
    return 0;
}

