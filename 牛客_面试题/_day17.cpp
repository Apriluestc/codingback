#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* 非严格升序排列
 * 牛牛有一个长度为n的整数序列,牛牛想对这个序列进行重排为一个非严格升序序列。
 * 牛牛比较懒惰,他想移动尽量少的数就完成重排,请你帮他计算一下他最少需要移动多少个序列中的元素。
 * (当一个元素不在它原来所在的位置,这个元素就是被移动了的)
 * */


int main()
{
    int res = 0;
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0;i < n;i++)
        cin >> num[i];
    vector<int> array(num);
    sort(num.begin(), num.end());
    for(int i = 0;i < n;i++)
        if(num[i] != array[i])
            res++;
    cout << res << endl;
    //std::cout << "Hello world" << std::endl;
    return 0;
}

