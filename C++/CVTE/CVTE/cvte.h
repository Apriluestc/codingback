#pragma once

#include <iostream>
using namespace std;

#include <string>

#define MAX(a, b) ((a > b) ? (a) : (b))		//带宏参数求两个数的最大值

void MAX_test()
{
	cout << "10 和 20 中的最大值：" << MAX(10, 20) << endl;
}

int CheckSystem()
{
	int address = 0x12345678;
	char*p = (char*)&address;
	return (p[0] == 0x78) && (p[1] == 0x56) && (p[2] == 0x34) && (p[3] == 0x12);	//小端模式
}

void CheckSystem_test()
{
	if (CheckSystem())
		cout << "小端模式" << endl;
	else
		cout << "大端模式" << endl;
}

template<class T>
T Max_Template(T left, T right)
{
	return (left > right) ? left : right;
}

void Max_Template_test()
{
	cout << "10 和 20 中的最大值：" << Max_Template<int>(10, 20) << endl;
}

bool StrToStr(string str)
{
	if (str.size() != 0)
	{
		char* start = &str[0];
		char* end = &str[str.size() - 1];
		while (start < end)
		{
			if (*start != *end)
				return false;
			start++;
			end--;
		}
		return true;
	}
	return true;
}

void StrToStr_test()
{
	string str1 = "abcdcba";
	string str2 = "abcdefa";
	cout << "abcdcba:" << StrToStr(str1) << endl;
	cout << "abcdefa:" << StrToStr(str2) << endl;
}

template<class T>
T Add(T left, T right)
{
	return left + right;
}

void Add_test()
{
	cout << "Add(10, 20):" << Add(10, 20) << endl;
	cout << "Add(10.0, 20.0):" << Add(10.0, 20.0) << endl;
	cout << "Add(10.0, 20):"<< Add<double>(10.0, 20) << endl;
	cout << "Add(a, 20):" << Add<char>('a', 20) << endl;
	cout << "Add(abc, def):" << Add<string>("abc", "def") << endl;
}

template <class T>
class ADD;

template <>
class ADD<int>
{
public:
	static int Add(int left, int right)
	{
		return left + right;
	}
};

template <>
class ADD<double>
{
public:
	static double Add(double left, double right)
	{
		return left + right;
	}
};

template <>
class ADD<string>
{
public:
	static string Add(string left, string right)
	{
		return left + right;
	}
};

void ADD_test()
{
	cout << "ADD<int>::Add(10, 20):" << ADD<int>::Add(10, 20) << endl;
	cout << "ADD<string>::Add(abc, def):" << ADD<string>::Add("abc", "defg") << endl;
	cout << "ADD<double>::Add(10.0, 20.8):" << ADD<double>::Add(10.0, 20.8) << endl;
	cout << "ADD<double>::Add(10.0, 8.8):" << ADD<double>::Add(10.0, 8.8) << endl;
}