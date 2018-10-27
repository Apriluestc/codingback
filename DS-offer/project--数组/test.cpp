#include <iostream>
#include<iomanip>
using namespace std;
int Getsize(int* array)
{
    return sizeof(array);
}

int main(int argc, char* argv[])
{
    int data1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1);
    int* data2 = data1;
    int size2 = sizeof(data2);
    int size3 = Getsize(data1);
    std::cout <<size1<<setw(2)<<size2<<setw(2)<<size3<< std::endl;
    return 0;
}

