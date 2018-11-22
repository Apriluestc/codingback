#include<iostream>

struct Date
{
public:
	void Display()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	Date (const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator == (const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	Date& operator = (const Date& d)
	{
		if(this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}
	/*
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator = (const Date& d);
	Date operator + (int days);
	Date operator += (int days);
	Date operator - (int days);
	Date operator -= (int days);
	int operator - (const Date& d);
	Date& operator ++ ();
	Date operator ++ (int);
	Date& operator -- ();
	Date operator -- (int);
	bool operator > (const Date& d);
	bool operator >= (const Date& d);
	bool operator < (const Date& d);
	bool operator <= (const Date& d);
	bool operator == (const Date& d);
	bool operator != (const Date& d);
	*/
	~Date()
	{}
	
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date date1;
	Date date2(2000, 1, 1);
	Date date3;
	date3 = date3.operator = (date2);
	date1.Display();
	date2.Display();
	date3.Display();
	return 0;
}