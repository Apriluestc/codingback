#pragma once
#include <iostream>
using namespace std;
#include <string>

void TestString()
{
	string s1;
	string s2("hello world!");
	string s3(10, 'a');
	string s4("hello world!", 10);
	
	cout << "s1:" << s1 << endl;
	cout << "capacity:" << s1.capacity() << endl;
	cout << "size:" << s1.size() << endl;
	
	s1.resize(20, '#');
	cout << "s1:" << s1 << endl;
	cout << "capacity:" << s1.capacity() << endl;
	cout << "size:" << s1.size() << endl;

	cout << s2 << endl;
	cout << s2.capacity() << endl;
	cout << s3 << endl;
	cout << s3.capacity() << endl;
	cout << s4 << endl;
	cout << s4.capacity() << endl;
}