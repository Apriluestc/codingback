#pragma once
#include <iostream>
using namespace std;

//不存在指向空值的引用这个事实意味着使用引用的代码效率比使用指针的要高。
//因为在使用之前不需要测试它的合法性。
void printInt(const int& ri)
{
	cout << ri << endl;//不需要测试ri，它肯定指向一个int值
}
//vs
void printInt(const int *pi)
{
	if (pi)
	{
		//检查pi是否为NULL
		cout << *pi<< endl;
	}
}