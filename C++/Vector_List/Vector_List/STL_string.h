#pragma once

#include <iostream>
using namespace std;

void test_string1()
{
	//string & list
	string s1("hello world!");
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < s1.size(); ++i)
	{
		hashtable[s1[i]]++;
	}
	cout << s1.max_size();
	cout << endl;
	//迭代器的使用
	//链表
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
