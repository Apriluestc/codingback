#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void func2()
{
	static int c = 10;
	int d = 10;

	char* p1 = "hello";
	char p2[] = "hello";
	int* ps = (int*)malloc(4);
	cout << strlen(p1) << endl;;
	cout << strlen(p2) << endl;
	cout << sizeof(p1) << endl;
	cout << sizeof(p2) << endl;
}
void func1()
{
	static int a1 = 10;
	int b = 10;
}
void Test1()
{
	func1();
	func2();
}
void Test2()
{
	int* p1 = new int;
	int* p2 = new int(10);		//调用构造函数
	int* p3 = new int[10];		//开辟数组
	cout << "p1:addr" << p1 << endl;
	cout << "p2:addr" << p2 << endl;
	cout << "p3:addr" << p3 << endl;
	delete p1;
	delete p2;
	delete[] p3;
	cout << "p1:addr" << p1 << endl;
	cout << "p2:addr" << p2 << endl;
	cout << "p3:addr" << p3 << endl;
}

//1、内置类型	new -- malloc 本质没区别
//2、自定义类型
//有了 malloc 为什么还要 new 
class AA
{
public:
	AA()
	{
		cout << "AA()" << endl;
	}
	~AA()
	{
		cout << "~AA()" << endl;
	}
};
void TestAA3()
{
	AA* p1 = (AA*)malloc(sizeof(AA));
	free(p1);
	//1、动态开辟空间
	//2、调用构造函数（初始化）和析构函数（清理）
	AA* p2 = new AA; 
	delete p2;
	AA* p3 = new AA[10];
	delete[] p3;	//	如何得知调用多少次析构
}

class MyVector
{
public:
	MyVector()
	{
		_a = new int[3];
		cout << "_a:addr" << _a << endl;
		cout << "MyVector()" << endl;
	}
	~MyVector()
	{
		delete _a;
		cout << "~MyVector" << endl;
	}
private:
	int* _a;
};
void TestMyVector4()
{
	MyVector* pv = (MyVector*)malloc(sizeof(MyVector));
	cout << "pv:addr" << pv << endl;
	free(pv);

	//char* p1 = (char*)malloc(0x7fffffff);
	//cout << "p1:addr" << p1 << endl;
	MyVector* ptr = new MyVector;
	cout << "ptr:addr" << ptr << endl;
	delete ptr;
}

//如何证明 operator new 不是重载
void Test5()
{
	int* p5 = (int*)operator new(4);
	cout << "p5:addr" << p5 << endl;
	int* p6 = (int*)malloc(4);
	cout << "p6:addr" << p6 << endl;
	//为什么会有	operator new
	//new 开空间并且调用构造或函数
	//	new开空间->operator new == malloc + 失败异常
	//2、调用构造
	//3、调用析构
	//4、释放空间	operator delete

}
void TestSize6()
{
	cout << sizeof(AA) << endl;
	cout << sizeof(MyVector) << endl;
}
//定位 new 表达式
void Test_allocator()
{
	allocator<AA> alloc;
	AA* p1 = alloc.deallocate(1);	//内存池
}