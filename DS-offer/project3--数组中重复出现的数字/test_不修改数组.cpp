#include <iostream>
#include<iomanip>   //引用 C++ 标准库头文件,调用函数 setw 格式化
using namespace std;
int countRange(const int* numbers, int length, int start, int end); //长度为 size 的数组,该函数将被调用 O(log(size)) 次;
int getDuplication(const int* numbers, int length)
{
    if(numbers == NULL || length <= 0)  //数组位空 || 长度小于 1
    {
        return false;
    }
    int start = 1;
    int end = length - 1;
    while(start <= end)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        if(end == start)
        {
            if(count < 1)
            {
                return start;
            }
            else
            {
                break;
            }
        }
        if(count > (middle - start + 1))
        {
            end = middle;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
}
int countRange(const int* numbers, int length, int start, int end)
{
    if(numbers == NULL)
    {
        return 0;
    }
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] >= start && numbers[i] <= end)
        {
            ++count;
        }
    }
    return count;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

