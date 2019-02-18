#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

/*
 * 牛牛有4根木棍,长度分别为a,b,c,d。
 * 羊羊家提供改变木棍长度的服务,如果牛牛支付一个硬币就可以让一根木棍的长度加一或者减一。
 * 牛牛需要用这四根木棍拼凑一个正方形出来,牛牛最少需要支付多少硬币才能让这四根木棍拼凑出正方形。
 * 拼凑正方形
 * */


int main()
{
    vector<int> h(4);
    for(int i = 0;i < 4;i++)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    int min1 = 3 * h[3] - h[0] - h[1] - h[2];
    int min2 = 2 * h[2] - h[1] - h[0] + (h[3] - h[2]);
    int min3 = h[1] - h[0] + (h[2] + h[3] - 2 * h[1]);
    int min4 = h[1] + h[2] + h[3] - 3 * h[0];
    int res = min1;
    if(res > min2)
        res = min2;
    if(res > min3)
        res = min3;
    if(res > min4)
        res = min4;
    cout << res << endl;
    return 0;
}

