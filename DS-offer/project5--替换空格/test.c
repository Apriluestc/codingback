#include <stdio.h>
//using namespace std;
#include<string.h>
void ReplaceBlank(char string[], int length)
{
    if(string == NULL || length <= 0)
    {
        return ;
    }
    /* originalLength 为字符串 string 的实际长度 */
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        ++originalLength;
        if(string[i] == ' ')
        {
            ++numberOfBlank;
        }
        ++i;
    }
    /* newLength 为把空格替换成 '%20' 之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
    {
        return ;
    }
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
    //int i = 0;
    for(i = 0; i < length; i++)
    {
        int j = 0;
        for(j = 0; j < length; j++)
        {
            printf("%s ", string);
        }
        printf("\n");

    }
    printf("\n");
}
int main()
{
    char* str = "We are happy.";
    int size = strlen(str);
    ReplaceBlank(str, size);
    /*
    int i = 0;
    for(i = 0; i < size; i++)
    {
        int j = 0;
        for(j = 0; j < size; j++)
        {
            printf("%s ", str);
        }
        printf("\n");
    }
    printf("\n");
    //std::cout << "Hello world" << std::endl;  */
    return 0;
}

