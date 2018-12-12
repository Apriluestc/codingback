#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <iostream>
using namespace std;

//1、传统写法		踏实		
#if 0
class String
{
public:
	String(const char* str)//初始化列表对自定义类型影响最大
		: _str = new char[_size + 1];	//空间  _size + 1
	{
		_str = new char[_size + 1];	//空间  _size + 1
		strcpy(_str, str);	//浅拷贝
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);	//深拷贝
	}
	String& operator=(const String& s)		//如果不写使用编译器默认给的，可能会造成内存泄漏	不写只完成值拷贝
	{
		char* tmp = new char[strlen(s._str) + 1];
		strcpy(tmp, s._str);
		delete[] _str;
		_str = tmp;
		return *this;
	}
	~String()
	{
		delete[] _str;
		_str = NULL;
	}
	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};
#endif

//2、现代写法
class String
{
public:
	String(const char* str)//初始化列表对自定义类型影响最大
		: _size(strlen(str))	//计算有效字符个数
		, _capacity(_size)	//容量  _capacity 和 _size 不算最后的 \0
	{
		_str = new char[_size + 1];	//空间  _size + 1
		strcpy(_str, str);	//浅拷贝
	}
	//s1.Swap(s2)
	void Swap(String&s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	String(const String& s)
		: _str(NULL)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}
	String& operator=(String s)		//如果不写使用编译器默认给的，可能会造成内存泄漏	不写只完成值拷贝
	{
		this->Swap(s);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	void PushBack(char ch);

	void Append(const char* str);
	void Insert(size_t pos, char ch);
	void Insert(size_t pos, const char* str);

	void PopBack();
	void Erase(size_t pos, size_t len);

	size_t Capacity();
	bool Empty();
	size_t Find(char ch);
	size_t Find(const char* sub);

	char& operator[](size_t pos)
	{
		return _str[pos];
	}

	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);

	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
	size_t _size;	
	//增容增加多少合适	不是一定增加二倍  但是二倍较好
	//增加 10 倍跟增加 8 倍的区别
	//如果每次都插入 “三四个元素 ”那么增加八倍十倍合适还是二倍合适
	size_t _capacity;
};

void TestString()
{
	String s1("hello");
	String s2(s1);
	cout << "c_str:" << s2.c_str() << endl;
	cout << "c_str:" << s1.c_str() << endl;
	String s3("worldsubstr!!!");
	s1 = s3;	
	//1、先开辟一个空间跟 s3 大小一样的空间
	//2、在拷贝过去
	//3、释放原先的小内存
	cout << "c_str:" << s1.c_str() << endl;
	cout << "c_str:" << s3.c_str() << endl;
	cout << "c_str:" << s1.c_str() << endl;
	cout << "c_str:" << s2.c_str() << endl;
	s1.Swap(s2);
	cout << "c_str:" << s1.c_str() << endl;
	cout << "c_str:" << s2.c_str() << endl;
}

//void PushBack(char ch);
//
//void Append(const char* str);
//void Insert(size_t pos, char ch);
//void Insert(size_t pos, const char* str);
//
//void PopBack();
//void Erase(size_t pos, size_t len);
//
//size_t Capacity();
//bool Empty();
//size_t Find(char ch);
//size_t Find(const char* sub);
//
//char& operator[](size_t pos)
//{
//	return _str[pos];
//}
//
//bool operator<(const String& s);
//bool operator<=(const String& s);
//bool operator>(const String& s);
//bool operator>=(const String& s);
//bool operator==(const String& s);
//bool operator!=(const String& s);


class Stringstr
{
public:
	Stringstr(char* str)				//String s1("hello world");  构造一个对象出来并且传 hello world 字符串常量以后的增删改查无法进行
		: _str(str)							//可以通过先开辟同样大小空间再进行拷贝数据
												//strcpy 拷贝会将 "\0" 拷贝		while(*dst++ = *src++){}	先拷贝再 ++ 
	{}
	~Stringstr()
	{}
private:
	char* _str;
};
void TestStringstr()
{
	Stringstr s1("hello world");
}