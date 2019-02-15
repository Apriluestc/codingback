#include <iostream>
using namespace std;
#include <string>


/*
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
 * 从前往后替换，后面的字符要不断往后移动，要多次移动，所以效率低下
 * 从后往前，先计算需要多少空间，然后从后往前移动，则每个字符只为移动一次，这样效率更高一点
 */


void replaceSpace(char *str,int length)
{
    //从前往后计数
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(str[i] == ' ')
            count++;                        
    }
    //从后往前移动
    for(int i = length - 1; i >= 0; i--)
    {
        if(str[i] != ' ')
        {
            str[i+2*count] = str[i];                                    
        }
        else
        {
            /*
            count--;
            str[i+2*count] = '%';
            str[i+2*count+1] = '2';
            str[i+2*count+2] = '0';
            */
            str[i+2*count] = '0';
            str[i+2*count-1] = '2';
            str[i+2*count-2] = '%';
            count--;
        }
    }
}


int main()
{
    char str[] = "We Are Happy!!!";
    replaceSpace(str, sizeof(str)/sizeof(char));
    cout << str << endl;
    return 0;
}

