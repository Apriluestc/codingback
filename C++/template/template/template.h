#include<iostream>
using namespace std;
template<class T>	//函数模板不是真正的函数,是编译器生成具体类型代码的工具
T Add(T left, T right)
{
	return left + right;
}
//模板初阶
//泛型编程
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(float& left, float& right)
{
	float temp = left;
	left = right;
	right = temp;
}
template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}
void TestAdd()
{
	int a = 10;
	int b = 20;
	double c = 30.0;
	cout << Add(a, b) << endl;
	//Add(a, c);	//该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演实参类型
	//通过实参 a 将 T 推演为 int ，通过实参 c 将 T 推演为 double ，但模板参数列表只有一个 T ，
	//编译器无法确定此处到底将 T 确定为什么类型而报错，
	//注意：在模板中编译器一般不会进行类型转换操作
	//此处有两种方式 1、用户自己转换 2、使用显式实例化
	Add(a, (int)c);
	Add<int>(a, c);	//显式实例化

	//如果类型不匹配，编译器会尝试隐式类型转化，如果无法进行转换就会报错
}
void TestSwap()
{
	int a = 10;
	int b = 20;
	cout <<  a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
}
//模板参数匹配原则
//一个非模板函数可以和一个已经存在的同名函数模板同时存在而且该函数模板还可以被实例化为这个非
//模板函数