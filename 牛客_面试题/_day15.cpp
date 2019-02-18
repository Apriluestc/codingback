#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>


/*
 * 输入描述：
 * 第一行：n，表示 h 数组元素个数
 * 第二行：n 个 h 数组元素
 * 第三行：m，表示 w 数组元素个数
 * 第四行：m 个 w 数组元素
 * */

/*
 * 六一儿童节老师带了很多好吃的巧克力到幼儿园。每块巧克力j的重量为w[j]，
 * 对于每个小朋友i，当他分到的巧克力大小达到h[i] (即w[j]>=h[i])，
 * 他才会上去表演节目。老师的目标是将巧克力分发给孩子们，使得最多的小孩上台表演。
 * 可以保证每个w[i]> 0且不能将多块巧克力分给一个孩子或将一块分给多个孩子
 * */

/*
 * n 表示学生个数
 * m 表示巧克力块数
 * h[i] 每个学生所要求的巧克力块的大小
 * w[j] 表示巧克力块的大小
 * */


int main()
{
    int result = 0;
    int n, m;
    cin >> n;
    vector<int> h(n);
    for(int i = 0;i < n;i++)
    {
        cin >> h[i];
    }
    cin >> m;
    vector<int> w(m);
    for(int j = 0;j < m;j++)
    {
        cin >> w[j];
    }
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());
    for(int i = 0, j = 0;i < n && j < m;j++)
    {
        if(w[j] >= h[i])
        {
            result++;
            i++;
        }
    }
    cout << result << endl;
    return 0;
}
