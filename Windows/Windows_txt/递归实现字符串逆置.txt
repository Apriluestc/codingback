#include<stdio.h>
#include<assert.h>
void strRev(char *str,int len)
{
    assert(str);
    if(*str == '\0')
        return;
    else
        strRev(str+1,len-1);
    printf("%c",*str);
}
int main()
{
	char arr[] = {'1','2','3','4','5','\0'};
	strRev(arr,5);
	return 0;
}