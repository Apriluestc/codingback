#include <iostream>
#include <vector>
using namespace std;

/*
 *输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 并保证奇数和奇数，偶数和偶数之间的相对位置不变
 */

void reOrderArray(vector<int>& array)
{
    int size = array.size();
    if(size == 0)
        return ;
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < size;j++)
            if(array[j] % 2 == 0 && array[j+1] % 2 == 1)
                swap(array[j], array[j+1]);
    }
}

int main()
{
    vector<int> array = {1,2,2,3,4,6,7,9,0};
    int size = array.size();
    reOrderArray(array);
    for(int i = 0;i < size;i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
