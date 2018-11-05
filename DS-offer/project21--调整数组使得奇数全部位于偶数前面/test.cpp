#include <iostream>
#include <iomanip>
//调整数组使得q奇数全部位于偶数前面

/* 

    奇数位于偶数前面;
    否则交换;
*/

void ReorderOddEven(int *pData, unsigned int len)
{
    if(pData == NULL || len == 0)
    {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData + len - 1;
    while(pBegin < pEnd)
    {
        //向后移动 pBegin 直到它指向偶数
        while(pBegin < pEnd && (*pBegin & 0x1) != 0)
        {
            pBegin++;
        }
        //向前移动 pEnd 直到它指向奇数;
        while(pBegin < pEnd & (*pEnd & 0x1) != 1)
        {
            pEnd--;
        }
        if(pBegin < pEnd)
        {
            std::swap(*pBegin, *pEnd);
            /*
            int _temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = _temp;
            */
        }
    }
}

//功能扩展

void Reorder(int *pData, unsigned int len, bool(*func)(int))
{
    if(pData == NULL || len == 0)
    {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData + len - 1;
    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && !func(*pBegin))
        {
            pBegin++;
        }
        while(pBegin < pEnd && func(*pEnd))
        {
            pEnd--;
        }
        if(pBegin < pEnd)
        {
            std::swap(*pBegin, *pEnd);
        }
    }
}
bool isEven(int n)
{
    return (n & 1) == 0;
}

void ReorderOddEven1(int *pData, unsigned int len)
{
    Reorder(pData, len, isEven);
}

int main()
{
    int pData[] = {1, 2, 3, 4, 5};
    int len = sizeof(pData)/sizeof(pData[0]);
    ReorderOddEven(pData, len);
    //ReorderOddEven1(pData, len);
    int i = 0;
    for(i = 0; i < len; i++)
    {
        std::cout << pData[i] << std::setw(2);
    }
    std::cout << std::endl;

    std::cout << "Hello world!" << std::endl;

    ReorderOddEven1(pData, len);
    for(i = 0; i < len; i++)
    {
        std::cout << pData[i] << std::setw(2);
    }
    std::cout << std::endl;
    //std::cout << "Hello world" << std::endl;
    return 0;
}

