#include<iostream>
#include<algorithm>
 
using namespace std;

/*
 *字符串价值
 有一种有趣的字符串价值计算公式，统计字符串中每种字符出现的次数，然后
 求所有字符出现次数的额平方和，以此作为字符串的价值
 例如: 字符串"abacaba",里面包括4个'a',2个'b',1个'c',于是这个字符串的价值为4 * 4 + 2 * 2 + 1 * 1 = 21
 牛牛有一个字符串s,并且允许你从s中移除最多k个字符,你的目标是让得到的字符串的价值最小。
 * */

/* 输入描述
 * 输入包括两行第一行为字符串 S 其中只包含小写字母
 * 第二行为整数 k 即为移除字符的个数
 * */


 
int main() {
    string s;
    int k;
    cin >> s >> k;
    int alph[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        alph[s[i] - 'a']++;
    }
    sort(alph, alph + 26);
    for (int i = 0; i < k; i++) {
        alph[25]--;
        sort(alph, alph + 26);
    }
    int value = 0;
    for (int i = 0; i < 26; i++) {
        value += alph[i] * alph[i];
    }
    cout << value << endl;
    return 0;
}
