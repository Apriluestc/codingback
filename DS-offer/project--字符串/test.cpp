#include <iostream>
#include<iomanip>
using namespace std;
#include<string.h>
int main(int argc, char* argv[])
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    int size1 = sizeof(str1);
    //str1 的字节数
    int length2 = strlen(str2);
    //str2 的长度
    const char* str3 = "hello world";
    const char* str4 = "hello world";
    int size3 = sizeof(str3);
    int length4 = strlen(str4);
    //str4 的长度
    //
    //str1 和 str2 不相等
    if(str1 == str2)
    {
        std::cout<<"str1 and str2 are same."<<std::endl;
    }
    else
    {
        std::cout<<"str1 and str2 are not same."<<std::endl;
    }
    if(str3 == str4)
    {
        std::cout<<"str3 and str4 are same."<<std::endl;
    }
    else
    {
        std::cout<<"str3 and str4 are not same."<<std::endl;
    }
    std::cout<<"str1_size:"<<setw(4)<<size1<<std::endl<<"str3_size:"<<setw(4)<<size3<<std::endl;
    std::cout<<"str2_length:"<<setw(4)<<length2<<std::endl<<"str4_length:"<<setw(4)<<length4<<std::endl;
    return 0;
}
