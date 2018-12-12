#pragma once
#include<iostream>
using namespace std;

//		自定义对象尽量传引用

class Date
{
	/*
	友元函数：
		1、不是类的成员函数
		2、可以访问类的私有成员变量
		3、友元函数不能用 const 修饰
		4、破坏了类的封装性
		5、友元函数可以在类的任何地方声明，不受访问限定符限制
		6、友元函数没有隐藏的 this 
		友元函数不需要通过对象来调用
	*/
	friend ostream& operator<<(ostream& _cout, const Date& d);		//友元函数
public:
	/*
	构造函数：是一种随着对象创建而自动被调用的公有成员函数，有且仅在定义对象时自动执行一次，对对象进行初始化
	特征：
		1、函数名与类名相同
		2、无返回值
		3、对象构造（对象实例化）时系统自动调用对应的构造函数
		4、构造函数可以重载
		5、构造函数可在类内定义也可在类外定义类内声明
		6、如果类定义没有给出构造函数，则 C++ 编译器自动产生一个默认的构造的函数，但只要我们定义了一个构造函数，系统就不会自动生成默认的构造函数
		7、无参的构造函数和全默认值的构造函数都认为时默认构造函数，并且认为默认构造函数只能有一个
	*/
	Date(int year = 1900, int month = 1, int day = 1)		//构造函数
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void Display()		//打印函数
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	/*
	拷贝构造函数：创建对象时能使同类对象来进行初始化，即拷贝构造函数
	特征：
		1、其实就是构造函数的一个重载
		2、拷贝构造函数参数只有一个并且只能使用引用传参，使用传值传参会引发无穷递归

	无穷递归的产生：
		1、在类的成员函数中可以直接访问同类对象的私有成员
		2、C++ 的访问限定符，是以类为单位，也就是说在这个单位内的成员可以互相访问

	*/
	Date(const Date& d)		//拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	/*
	类的赋值操作符重载
		1、对一个已经存在的对象进行拷贝赋值
	*/
	Date& operator=(const Date& d)		//赋值函数（运算符重载）
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}
	Date operator+(int days)
	{
		_day += days;
		while (_day > 30)
		{
			_day -= 30;
			_month += 1;
		}
		while (_month > 12)
		{
			_month -= 12;
			_year += 1;
		}
		return *this;
	}
	Date operator+=(int days);
	Date operator-(int days);
	Date operator-=(int days);
	int operator-(const Date& d);
	Date& operator++()		//年份自增函数
	{
		_day++;
		while (_day > 30)
		{
			_day -= 30;
			_month += 1;
		}
		while (_month > 12)
		{
			_month -= 12;
			_year += 1;
		}
		return *this;
	}
	Date operator++(int);
	Date& operator--()		//年份自减函数
	{
		_day --;
		while (_day < 1)
		{
			_day = 30;
			_month -= 1;
		}
		while (_month < 1)
		{
			_month = 12;
			_year -= 1;
		}
		return *this;
	}
	Date operator--(int);
	bool operator>(const Date& d)		//2018-1-1 > 1990-1-1
	{
		return _year > d._year
			|| (_year == d._year && _month > d._month)
			|| (_year == d._year && _month == d._month && _day > d._day);
	}
	bool operator>=(const Date& d)		//2018-10-10 >= 2018-9-10
	{
		if (_year >= d._year
			|| (_year == d._year && _month >= d._month)
			|| (_year == d._year && _month == d._month && _day >= d._day))
		{
			cout << "true" << endl;		//条件成立打印 true 
			return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		}
	}
	bool operator<(const Date& d)
	{
		if (_year < d._year
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			cout << "true" << endl;
			return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		}
	}
	bool operator<=(const Date& d)
	{
		if (_year <= d._year
			|| (_year == d._year && _month <= d._month)
			|| (_year == d._year && _month == d._month && _day <= d._day))
		{
			cout << "true" << endl;
			return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		}
		
	}
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date & d)
	{
		return _year != d._year
			|| _month != d._month
			|| _day != d._day;
	}
	/*
	析构函数：当一个对象的生命周期结束时，C++ 编译器会自动调用一个成员函数，即析构函数
	特征：
		1、析构函数构成		~类名
		2、无参数无返回值
		3、一个类有且只有一个析构函数
		4、对象生命周期结束时，自动调用析构函数
		析构函数不是删除对象，而是对对象删除前的一些删除工作
	*/
	~Date()
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
}
void TestDate()
{
	Date date1;
	cout << date1 << endl;
	Date date2(2000, 1, 1);
	Date date3;
	Date date4 = date2;
	Date date5(1997, 1, 10);
	Date date6(1999, 1, 1);
	date4.Display();
	date5.Display();
	date5.operator++();
	date5.Display();
	date5.operator--();
	date5.Display();
	date5.operator<(date6);
	date2.operator>=(date1);
	date6.Display();
	date1.operator<(date2);
	date1.operator==(date2);
	date1.operator>=(date2);
	date5.operator<=(date6);
	date5.operator>=(date6);
	date1.Display();
	date2.Display();
	date2.operator+(80);
	date2.Display();
	date3.Display();
	date3.operator--();
	date3.Display();
	date3.operator<(date1);
	date5.operator<(date1);
	date4.Display();
	date4.operator++();
	date4.Display();
}
