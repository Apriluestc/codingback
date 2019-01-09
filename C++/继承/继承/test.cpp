#include <iostream>
#include <string>
using namespace std;



//继承：代码复用，在保持原有类型的基础上进行扩展，增加新功能
//继承呈现了面向对象程序设计层次结构，体现了由简单到复杂的认知过程，继承是类设计层次的复用
class Person {
public:  
	void Print()
	{ 
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	} 
protected:    
	string _name = "peter"; // 姓名   
	int _age = 18;  // 年龄 
};

#if 0
//继承后父类的Person的成员都会变成子类的一部分
//这里体现出了Student和 Teacher复用了Person的成员
class Student : public Person
{
protected:    
	int _stuid; // 学号 
}; 
class Teacher : public Person 
{
protected:  
	int _jobid; // 工号 
};

class Post
{
public:
	void Print()
	{
		cout << "_deptno:" << _deptno << endl;
		cout << _sex << _sex << endl;
	}
private:
	int _deptno = 110;
	string _sex = "男";
};
class Worker : public Post
{
public:
	Worker(string name)
		: _name(name)
	{}
	Worker()
	{}
	~Worker()
	{}
private:
	string _name;
};

class Emp : public Post
{
public:
	Emp(string name, int deptno)
		: _name(name)
		, _deptno(deptno)
	{}
	Emp()
	{}
	~Emp()
	{}
private:
	string _name;
	int _deptno;
};
int main()
{
	Student s;  
	Teacher t;
	s.Print();    
	t.Print();
	Emp e;
	Worker w;
	e.Print();
	w.Print();
	return 0;
}

#endif

//继承定义
//class Empno : public Person
//其中 Person 是父类也称基类，Empno 是子类也称派生类
//继承方式：public、private、protected 三种


class Empno : public Person
{
public:
	Empno(int no)
		:_no(no)
	{}
	~Empno()
	{}
private:
	int _no;
};

/*
+----------------------+--------------------------+--------------------------+-----------------------+
| 类成员/继承方式	   |		public 继承		  |		protected 继承		 |		private 继承     |
+----------------------+--------------------------+--------------------------+-----------------------+
|基类的 public 成员	   |   派生类的 public 成员	  |  派生类的 protected 成员 |	派生类的 private 成员|
+----------------------+--------------------------+--------------------------+-----------------------+
|基类的 protected 成员 |   派生类的 protected 成员|	 派生类的 protected 成员 |	派生类的 private 成员|
+----------------------+--------------------------+--------------------------+-----------------------+
|积累的 private 成员   |      派生类中不可见	  |		  派生类中不可见     |        派生类中不可见  |
+----------------------+--------------------------+--------------------------+-----------------------+
*/

//总而言之，基类的 private 成员在派生类中无论以什么方式继承都是不可见的
class Student : public Person
{
protected: 
	int _stunum; // 学号 
};
//Student 继承了 Person 就可以认为，Student 复用了类 Person 的成员及成员函数
//继承允许你根据基类类的实现来定义派生类的实现。
//在继承方式中，基类的内部细节对子类可见 。
//继承一定程度破坏了基类的封装，基类的改变，对派生类类有很大的影响。派生类和基类间的依赖关系很强，耦合度高

//基类和派生类对象赋值转换
//派生类对象可以赋值给基类的对象/基类的指针/基类的引用
//这里有个形象的说法叫切片或者切 割。寓意把派生类中父类那部分切来赋值过去
//基类对象不能赋值给派生类对象 基类的指针可以通过强制类型转换赋值给派生类的指针
//但是必须是基类的指针是指向派生类对象时才 是安全的。这里基类如果是多态类型

class Person
{
protected:
	string _name; // 姓名 
	string _sex;  // 性别 
	int _age;    // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号 
};
void Test ()
{
	Student sobj ;
	// 1.子类对象可以赋值给父类对象/指针/引用    
	Person pobj = sobj ; 
	Person* pp = &sobj;
	Person& rp = sobj;    
	//2.基类对象不能赋值给派生类对象    
	//sobj = pobj;				-------------错误
	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针    
	pp = &sobj;
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。  
	ps1->_No = 10;    
	pp = &pobj; 
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题   
	ps2->_No = 10;
}

//继承中的作用域