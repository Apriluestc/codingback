#include <iostream>
using namespace std;
#include <string>

template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}
	T* operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	~AutoPtr()
	{
		delete _ptr;
	}
protected:
	T* _ptr;
};

class A
{
public:
	A()
	{}
	~A()
	{
		cout << "~A(){}" << endl;
	}
private:
};
void test1()
{
	AutoPtr<A> ap(new A);
	string s;
	cin >> s;
	size_t pos;
	cin >> pos;
	cout << s.at(pos) << endl;
}

void test2()
{
	auto_ptr<int> ap(new int);
	string s;
	cin >> s;
	size_t pos;
	cin >> pos;
	cout << s.at(pos) << endl;
}

void test3()
{
	auto_ptr<A> ap1(new A);
	auto_ptr<A> ap2 = ap1;
	AutoPtr<A> ap3(new A);
	AutoPtr<A> ap4 = ap3;		//拷贝构造,析构了两次，程序崩溃，浅拷贝
}

int main()
{
	try
	{
		test2();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
	return 0;
}