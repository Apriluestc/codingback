#include <iostream>
#include <limits.h>
using namespace std;
#include <algorithm>
#include <vector>

/*
 * 最大乘积
 * 
 * 给定无序数组，要求得出三个数相乘的最大乘积
 *
 * 首先给给定数组进行排序，所得最大乘积即是前三大的数相乘，
 * 
 * 或者两个最小的数和最大数者三者的乘积
 *
 * 比如给定数组：[1,2,5,4,3,-1,-8]
 *
 * 定义出最大数：max_fir = INT_MIN, max_sec = INT_MIN, max_thr = INT_MIN;
 * 
 * 最小数：      min_fir = INT_MAX, min_sec = INT_MAX;
 *
 * mul1 = max_fir * max_sec * max_thr;
 *
 * mul2 = min_fir * min_sec * max_fir;
 *
 * 这两者最大数即为答案
 *
 * */

/*
 *
int maxMul(vector<int> array, int length)
{
    if(length == 0)
        return 0;
    qsort(array.begin(), array.end());
    int mul1 = array[length-3] * array[length-2] * array[length-1];
    int mul2 = array[0] * array[2] * array[length-1];
    int mul = mul1 > mul2 ? mul1 : mul2;
    return mul;
}

void test()
{
    vector<int> array = {-1,-4,2,5,7,9,1};
    int lenth = array.size();
    int res = maxMul(array, lenth);
    cout << res << endl;
}

int main()
{
    test();
    return 0;
}

*/


int main()
{
    long long max_fir = INT_MIN, max_sec = INT_MIN, max_thr = INT_MIN;
    long long min_fir = INT_MAX, min_sec = INT_MAX;
    int n, res;
    long long mul;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> res;
        if(res < min_fir)
        {
            min_sec = min_fir;
            min_fir = res;
        }
        else if(res < min_sec)
        {
            min_sec = res;
        }
        if(res > max_fir)
        {
            max_thr = max_sec;
            max_sec = max_fir;
            max_fir = res;
        }
        else if(res > max_sec)
        {
            max_thr = max_sec;
            max_sec = res;
        }
        else if(res > max_thr)
        { 
            max_thr = res;
        }
    }
    mul = max_fir * max_sec * max_thr > max_fir * min_fir * min_sec ? max_fir * max_sec * max_thr : max_fir * min_fir * min_sec;
    cout << mul << endl;
    return 0;
}

