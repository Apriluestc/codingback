#include <iostream>
using namespace std;

int Add(int left, int right)
{
	return left + right;
}

int Sub(int left, int right)
{
	return left - right;
}
int Mul(int left, int right)
{
	return left * right;
}
int Div(int left, int right)
{
	return left / right;
}

#if 0

int main()
{
	int x = 0;
	int y = 0;
	int input = 1;
	int ret = 0;
	while (input)
	{
		cout << "****************************" << endl;
		cout << "****	1.add	2.sub	****" << endl;
		cout << "****	3.mul	4.div	****" << endl;
		cout << "****************************" << endl;
		cout << "请选择：";
		cin >> input;
		switch (input)
		{
		case 1:
			cout >> "请输入操作数：";
			cin >> x, y;
			ret = Add(x, y);
			break;
		case 2:
			cout >> "请输入操作数：";
			cin >> x, y;
			ret = Sub(x, y);
			break;
		case 3:
			cout >> "请输入操作数：";
			cin >> x, y;
			ret = Mul(x, y);
			break;
		case 4:
			cout >> "请输入操作数：";
			cin >> x, y;
			ret = Div(x, y);
			break;
		default:
			cout << "选择错误" << endl;
			break;
		}
		cout << "ret = " << ret;
	}
	return 0;
}

#endif

int main()
{
	int x = 0; 
	int y = 0;
	int input = 1;
	int ret = 0;
	int(*res[5])(int x, int y) = { 0, Add, Sub, Mul, Div };
	while (input)
	{
		cout << "****************************" << endl;
		cout << "****	1.add	2.sub	****" << endl;
		cout << "****	3.mul	4.div	****" << endl;
		cout << "****************************" << endl;
		cout << "请选择：";
		cin >> input;
		if (input<=4 && input>=1)
		{
			cout << "请输入操作数：";
			cin >> x, y;
			ret = (*res[input])(x, y);
		}
		else
			cout << "输入有误" << endl;
		cout << "ret = " << ret << endl;
	}
	return 0;
}
