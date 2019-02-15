#include <iostream>
using namespace std;

/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）
 * 
 * */


int Fibonacci(int n)
{
    int zer = 0;
    int fir = 1;
    int res = 0;
    if(n == 0)
        return zer;
    if(n == 1)
        return fir;
    for(int i = 2;i <= n;i++)
    {
        res = zer + fir;
        zer = fir;
        fir = res;
    }
    return res;
}


int main()
{
    int n = 10;
    int result = Fibonacci(n);
    cout << result << endl;
    return 0;
}

