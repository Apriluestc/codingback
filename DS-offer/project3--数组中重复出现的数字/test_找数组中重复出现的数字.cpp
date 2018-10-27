#include <iostream>
#include<iomanip>
using namespace std;
void Swap(int*pa, int* pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == NULL || length < 0)
    {
        return false;
    }
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
        {
            return false;
        }
    }
    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            Swap(&numbers[i], &numbers[numbers[i]]);
        }
    }
    return false;
}
int main()
{
    int array[] = {2, 3, 1, 0, 2, 5, 3};
    int size = sizeof(array);
    int* duplication = NULL;
    std::cout <<setw(2)<<duplicate(array, size, duplication)<< std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}


