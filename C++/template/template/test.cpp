#include "template.h"
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);//模板一般不会进行类型转换
	cout << Add(1.0, 2.0) << endl;
	TestAdd();
	TestSwap();
	return 0;
}