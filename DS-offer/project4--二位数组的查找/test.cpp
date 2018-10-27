#include <iostream>
#include<iomanip>
using namespace std;
bool Find(int* array, int rows, int cols, int number)
{
    bool found = false;
    if(array != NULL && rows > 0 && cols > 0)
    {
        int row = 0;
        int col = cols - 1;//从右上角开始找
        while(row < rows && cols > 0)
        {
            if(array[row * cols +col] == number)
            {
                found = true;
                break;
            }
            else if(array[row * cols + col] > number)
            {
                --col;
            }
            else
            {
                ++row;
            }
        }
    }
    return found;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

