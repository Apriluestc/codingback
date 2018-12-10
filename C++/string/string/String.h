#pragma once
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

//	string 类的常见对象的构造
/*
	string();	//	构造空的 string 类对象
	string(const char* s);	// 使用 c 风格的的字符串来构造 string 类对象
	string(size_t n, char c);	//	string 类对象中包含 n 个字符 c
	string(const string& s);	//	拷贝构造函数
	string(const string& s, size_t n);	//	用 s 中的前 n 个字符构造 string 类的对象
*/

void TestString1()
{
	cout << "string 类的常见对象的构造" << endl;
	string s1;	//	构造空的 string 类对象 s1
	string s2("hello world!!!");	//	使用 c 格式构造 string 类的对象 s2
	string s3(10, 'h');	//	用 10 给字符 h 构造 string 类对象 s3
	string s4(s2);	//	用 s2 构造 string 类对象 s4
	string s5(s3, 5);	//	用字符串 s3 的前五个字符构造 string 类对象 s5
}

// string 类的对象的容量操作
/*
	size_t size() const	返回字符串的有效字符长度
	size_t length() const	返回字符串的有效字符长度
	size_t capacity() const		返回容量，总空间大小
	bool empty() const		检测字符串是否为空串
	void clear()	清空有效字符
	void resize(size_t n, char c)		将有效字符个数改为 n 个，多出的空间用字符 c 填充
	void resize(size_t n)		将有效字符个数改为 n 个，多出的空间用 0 填充
	void reserve(size_t res_arg = 0)	为字符串预留空间
*/

void TestString2()
{
	cout << "string 类的对象的容量操作" << endl;
	//	string 类对象直接支持 cin 和 cout 输入与输出
	string s("hello world!!!");
	cout << "length:" << s.length() << endl;
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//	将 s 中的字符串清空，注意：清空时只是将 size 清 0，不改变底层空间大小
	s.clear();
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//将 s 中有效字符个数增加到 10 个，多出位置用字符 a 进行填充
	s.resize(10, 'a');
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//将 s 中有效字符个数增加至 15 个，多出位置用 '\0' 进行填充
	//"aaaaaaaaaa\0\0\0\0\0\0\0\0\0\0"
	s.resize(15);
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//将 s 中有效字符减少至 5 个
	s.resize(5);
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;
}

void TestString3()
{
	cout << "测试 reserve 是否会改变 string 中有效元素个数" << endl;
	//测试 reserve 是否会改变 string 中有效元素个数
	string s;
	s.reserve(100);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	//测试 reserve 参数小于 string 底层空间大小时，是否会将空间缩小
	s.reserve(50);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
}
//注意：

/*
		1、size() 和 length() 方法底层实现原理完全相同，引入 size() 的原因
	是为了与其他容器的接口保持一致，一般情况下基本都用 size()
		2、clear() 只是将 string 中的有效字符清空，不改变底层空间大小
		3、resize(size_t n) 与 resize(size_t n, char c) 都是将字符串中有效字符个数改变成 n 个，
	不同的是当字符个数增多时，resize(n) 用 0 来填充剩余空间，而 resize(size_t n, char c) 则用字符填充
	注意：resize() 在改变元素个数时，如果将元素个数增多，可能会改变底层容量大小 capacity ，
	如果是减少有效元素个数，则底层空间大小不变
		4、reserve(size_t res_arg = 0) 为 string 预留空间，不改变有效元素个数，
	当 reserve 的参数小于 string 的底层空间时，reserve 不会改变容量大小
*/

//string 类对象的访问操作

/*
	char& operator[](size_t pos)		返回位置 pos 的字符，const string 类对象调用
	const char& operator[](size_t pos)		//返回 pos 位置的字符，非 const string 类对象调用
*/

void TestString4()
{
	string s1("hello world!!!");
	const string s2("hello world!!!");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << "s1:" << s1 << endl;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << "s1:" << s1[i];
	}
	cout << endl;
	//s2[0] = 'H'	不能通过编译 ， const 类型对象不可以修改
}

// string 类对象的修改操作

/*
	void push_bask(char c);	在字符串尾插入字符 c
	string& append(const char* s);	在字符串后面追加一个字符串
	string& operator+=(const string& str);	在字符串后面追加字符串
	string& operator+=(const char* c);	在字符串后面追加 c 风格字符串
	string& operator+=(const char c)	在字符串后面追加字符 c
	const char* c_str() const	返回 c 风格的字符串
	size_t find(char c, size_t pos = 0) const	从字符串 pos 位置往后开始找字符 c ，返回该字符所在字符串的位置
	size_t rfind(char* c, size_t pos = npos) const		从字符串 pos 位置开始向前找字符 c ，返回该字符所在位置
	string substr(size_t pos = 0, size_t n = npos) const		在 str 中从 pos 位置开始截取 n 个字符，然后将其返回 
*/


void TestString5()
{
	string str;  
	str.push_back(' ');   // 在str后插入空格    
	str.append("hello");  // 在str后追加一个字符"hello"  
	str += 'b';           // 在str后追加一个字符'b'
	str += "it";          // 在str后追加一个字符串"it"    
	cout<<str<<endl; 
	cout<<str.c_str()<<endl;   // 以C语言的方式打印字符串      
	// 获取file的后缀    
	string file("string.cpp"); 
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size()-pos));
	cout << suffix << endl;      
	
	// npos是string里面的一个静态成员变量    
	// static const size_t npos = -1;
	// 取出url中的域名    
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;      
		return;   
	}
	start += 3;    
	size_t finish = url.find('/', start); 
	string address = url.substr(start, finish - start);    
	cout << address << endl;    
	// 删除url的协议前缀    
	pos = url.find("://");
	url.erase(0, pos+3);  
	cout<<url<<endl;
}

void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void TestPushBack_P()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
/*
注意：
		1. 在string尾部追加字符时，s.push_back(c) / s.append(1, c) / s += 'c'三种的实现方式差不多，
一般 情况下string类的 += 操作用的比较多， += 操作不仅可以连接单个字符，还可以连接字符串。 
		2. 对string操作时，如果能够大概预估到放多少字符，可以先通过reserve把空间预留好。
*/

/*
	string 类的非成员函数
	operator+();
	operator<<();
	operator>>();
	getline()	获取一行字符串
	relational operators		字符串大小比较
*/

#if 0
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//几个常见的笔试题

//翻转字符串
string reverseString(string s)
{
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return s;
}
//找字符串中只出现一次的字符
int firstUniqueChar(string s)
{
	//统计每个字符出现的次数
	size_t array[256] = { 0 };
	int size = s.size();
	for (size_t i = 0; i < size; ++i)
	{
		array[s[i]] += 1;
	}
	//按照字符次序从前往后找只出现一次的字符
	for (size_t i = 0; i < size; ++i)
	{
		if (array[s[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}

//字符串最后一个单词的长度
int _main()
{
	string line;
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	return 0;
}

//字符串转整型数字
//字符串的空格替换
//字符串相加
//验证是否为回文
//字符串相乘

#include <assert.h>
//传统写法 string 类
class String
{
public:
	String(const char* str = "")
	{
		//构造 string 类对象时，如果传递 nullptr 指针，认为程序非法
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	//析构函数仅仅析构构造函数开辟出来的空间
	~String()
	{
		delete[] _str;
		_str = nullptr;
	}

private:
	char* _str;
};

//现代写法 string 类
namespace mod
{
	class String
	{
	public:
		String(const char* str = "")
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			: _str(nullptr)
		{
			String strTmp(s._str);
			swap(_str, strTmp._str);
		}
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				String strTmp(s._str);//用传入参数构造当前对象，然后交换
				swap(_str, strTmp._str);
			}
		}
		~String()
		{
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
}
/*
	传统写法与现代写法的区别
	1、传统写法代码可读性高
	2、现代写法代码简洁，可维护性高， new 和 delete 都在一处
*/
#endif

//string 的模拟实现
namespace fun
{
	class String
	{
	public:
		String(const char* str = "")
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			: _str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char* pStr = new char[s._capacity + 1];
				strcpy(pStr, s._str);

				delete[] _str;
				_str = pStr;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	public:
		void pushback(char c)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void append(size_t n, char c)
		{
			for (size_t i = 0; i < n; ++i)
			{
				pushback(c);
			}
		}
		void reserve(size_t newcapacity)
		{
			//如果新容量大于旧容量，则开辟新空间
			if (newcapacity > _capacity)
			{
				char* str = new char[newcapacity + 1];
				strcpy(str, _str);//把旧空间内容拷贝至新空间
				//释放旧空间，然后使用新空间
				delete[] _str;
				_str = str;
				_capacity = newcapacity;
			}
		}
		String& operator+=(char c)
		{
			pushback(c);
			return *this;
		}
		String& operator+=(const char* str);//追加字符串
		void resize(size_t newsize, char c = char())
		{
			if (newsize > _size)
			{
				//如果 newsize 大于底层空间大小，则需要开辟空间
				if (newsize > _capacity)
				{
					reserve(newsize);
				}
				memset(_str + _size, c, newsize - _size);
			}
			_size = newsize;
			_str[newsize] = '\0';
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
