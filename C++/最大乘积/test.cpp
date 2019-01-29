#include <iostream>
using namespace std;
#include <limits.h>

int main()
{
    long long max_fir = INT_MIN, max_sec = INT_MIN, max_thr = INT_MIN;
    long long min_fir = INT_MAX, min_sec = INT_MAX;
    int n, res;
    long long mul;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> res;
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
        if(res < min_fir)
        {
            min_sec = min_fir;
            min_fir = res;
        }
        else if(res < min_sec)
        {
            min_sec = res;
        }
    }
    mul = (max_fir * max_sec * max_thr) > (max_fir * min_fir * min_sec) ? (max_fir * max_sec * max_thr) :(max_fir * min_fir * min_sec);
    cout << mul <<endl;
    //std::cout << "Hello world" << std::endl;
    return 0;
}

