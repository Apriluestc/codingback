#include <iostream>

using namespace std;


/*
 *一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）
 *
 * a.如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1);
 *
 * b.假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n-2)
 *
 * c.由a\b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2) 
 *
 * d.然后通过实际的情况可以得出：只有一阶的时候 f(1) = 1 ,只有两阶的时候可以有 f(2) = 2
 *
 * e.可以发现最终得出的是一个斐波那契数列：
 * 
 * */


int JumpFloor(int number)
{
    if(number == 1)
        return 1;
    else if(number == 2)
        return 2;
    else
        return JumpFloor(number -1) + JumpFloor(number - 2);
}


int jumpfloor(int number)
{
    int zer = 0;
    int fir = 1;
    int sec = 2;
    if(number == 1)
        return fir;
    if(number == 2)
        return sec;
    int res = 0;
    for(int i = 3;i <= number;i++)
    {
        res = fir + sec;
        fir = sec;
        sec = res;
    }
    return res;
    /*
    if(number <= 0)
        return 0;
    else if(number == 1)
        return 1;
    else if(number == 2)
        return 2;
    else
        return jumpfloor(number-1) + jumpfloor(number-2);
        */
}


int main()
{
    int number = 5;
    int res1 = JumpFloor(number);
    cout << res1 << endl;
    int res2 = jumpfloor(number);
    cout << res2 << endl;
    return 0;
}

