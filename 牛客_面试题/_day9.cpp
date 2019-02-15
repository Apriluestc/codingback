#include <iostream>
using namespace std;


/*
 *二进制中 1 的个数
 * 
 */


int NumberOf1(int n)
{
    if(n == 0)
        return 0;
    int count = 0;
    while(n != 1)
    {
        n /= 2;
        count++;
    }
    return count + 1;
}

int numberofone(int n)
{
    int count = 0;
    while(n)
    {
        if(n % 2 == 1)
            count++;
        n /= 2;
    }
    return count;
}


int numberof(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            count++;
        flag <<= 1;
    }
    return count;
}

int main()
{
    int  n = 7;
    int res1 = NumberOf1(n);
    int res2 = numberofone(n);
    int res3 = numberof(n);
    cout << res3 << endl;
    cout << res1 << endl;
    cout << res2 << endl;
    return 0;
}

