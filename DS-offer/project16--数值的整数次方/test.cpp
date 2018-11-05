#include <iostream>
double Power(double base, unsigned int exponent)
{
    double result = 1.0;
    int i = 0;
    for(i = 0; i <= exponent; i++)
    {
        if(i == 0)
        {
            return 1;
        }
        if(i == 1)
        {
            return base;
        }
        else
        {
            result *= base;
        }
    }
    return result;
}

//数值的整数次方
/* 

   a ** n = a ** (n / 2) * a ** (n / 2){n为偶数}
   a ** n = a ** ((n - 1) / 2) * a ** ((n - 1) / 2){n为奇数}
*/
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0)
    {
        return 1;
    }
    if(exponent == 1)
    {
        return base;
    }
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1) //  w按位与运算代替求余判断一个数是不是奇数
    {
        result *= base;
    }
    return result;
}
int main()
{
    double base = 2.0;
    unsigned int exponent = 30;
    std::cout << PowerWithUnsignedExponent(base, exponent) << std::endl;
    std::cout << Power(base, exponent) << std::endl;
    //std::cout << "Hello world" << std::endl;
    return 0;
}

