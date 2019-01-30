#include<iostream>
#include<string>
using namespace std;
//移位进位法
string Mul(string left, string right)
{

	size_t Lsize = left.size();
	size_t Rsize = right.size();
	size_t Size = Lsize + Rsize;
	string res(Size, '0');

	int takevoer = 0;//进位
	int offset = 0;//移位

	size_t idx = 1, j = 1;
	for (idx = 1; idx <= Rsize; ++idx)
	{
		takevoer = 0;
		int rightnum = right[Rsize - idx] - '0';
		//计算每一位与left相乘
		for (j = 1; j <= Lsize; ++j)
		{
			char resBit = res[Size - j - offset] - '0';
			int num = rightnum * (left[Lsize - j] - '0') + takevoer + resBit;
			takevoer = num / 10;
			res[Size - j - offset] = num % 10 + '0';
		}
		if (takevoer != 0)
			res[Size - j - offset] = takevoer + '0';
		offset++;
	}

	//如果没有进位的话，res最高位没有数字
	if (res[0] == '0')
		res.erase(0, 1);
	return res;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	string str = Mul(s1, s2);
	cout << str << endl;
}