#include <iostream>
using namespace std;

/*
多态的概念:同一操作作用于不同类对象会产生不同的效果，通俗来说就是完成某个行为，不同类对象完成时会产生不同状态
比如，买车票这个行为，学生买的就是学生票，而成人买的就是成人票


多态的定义及实现
多态是在不同继承关系中的类对象，去调用同一函数，产生了不同行为
在继承体系中构成多态的必要条件：
	1、调用函数的对象必须是指针或者引用
	2、被调用的函数必须还是虚函数，且完成了虚函数的重写

	引出：什么是虚函数？被 virtual 关键字修饰的类的成员函数是虚函数
什么是虚函数重写？
	派生类中有一个跟基类完全相同的虚函数，我们就称子类的虚函数重写了基类的虚函数，完全相同是指函数名，参数列表，函数返回值类型

虚函数重写的例外：协变虚函数重写的例外：协变 
	虚函数重写有一个例外：重写的虚函数的返回值可以不同，但是必须分别是基类指针和派生类指针或者基类 引用和派生类引用。

派生类中重写的虚函数不加 virtual 关键字也可以构成重写，但这样是不规范的
析构函数的重写：
	基类中的析构函数如果是虚函数，那么派生类的析构函数就重写了基类的析构函数。这里他们的函数名不相 同，
	看起来违背了重写的规则，其实不然，这里可以理解为编译器对析构函数的名称做了特殊处理，
	编译后 析构函数的名称统一处理成destructor，这也说明的基类的析构函数最好写成虚函数
C++ 中用 override 修饰派生类函数强制完成重写，如果没有重写则编译报错
final 修饰基类的虚函数不能被派生类重写

多态的原理-虚函数表
派生类虚表生成：
	1、先将基类中的虚表内容拷贝一份到派生类中的虚表当中
	2、如果派生类重写了某个基类中的虚函数，用派生类自己的虚函数覆盖基类中的虚函数，
	3、派生类自己新增加的虚函数，按其在派生类中的声明顺序一次增加到派生类虚表的最后
	4、虚函数表的本质：存放虚函数指针的指针数组，这个数组的最后存放的是 nullptr
	5、只有虚函数才会放进虚表
	6、虚函数指针存放在虚表中，虚函数存在于代码段，另外对象中存放的是虚表指针
多态常见面试题

*/

class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}
	virtual void BuyTicket()
	{
		cout << "买票-全价" << endl;
	}
};

class Student : public Person
{
public:
	Student()
	{}
	virtual void BuyTicket()
	{
		cout << "买票-半价" << endl;
	}
	virtual ~Student()
	{
		cout << "~Student" << endl;
	}
private:
};

void Func(Person& p)
{
	p.BuyTicket();
}

class A{};
class B : public A{};
class person
{
	virtual A* f()
	{
		return new A;
	}
};
class student : public person
{
public:
	virtual B* f()
	{
		return new B;
	}
};

class Car
{
public:
	virtual void Drive()
	{}
};

class Benz : public Car
{
public:
	//ocerride 修饰派生类虚函数强制完成重写，如果没有重写则编译报错
	virtual void Drive() override
	{
		cout << "Benz - 舒适" << endl;
	}
};

#if 0
class Carn
{
public:
	//final 修饰的基类虚函数不能被派生类重写
	virtual void Driven() final
	{}
};

class Benzn : public Carn
{
public:
	//ocerride 修饰派生类虚函数强制完成重写，如果没有重写则编译报错
	virtual void Driven() 
	{
		cout << "Benzn - 舒适" << endl;
	}
};

#endif
class Base
{
public:
	//一个含有虚函数的类中至少含有一个虚函数表指针，因为虚函数的地址要被存放在虚表当中
	//此类中除了 _b 成员，还有一个 _vfptr 指针放在对象的前面或者后面（这与平台有关）
	virtual void Func()
	{
		cout << "Func()" << endl;
	}
private:
	int _b = 1;
};

namespace Bit
{
	class Base
	{
	public:
		virtual void Func1()
		{
			cout << "Base::Func1" << endl;
		}
		virtual void Func2()
		{
			cout << "Base::Func2" << endl;
		}
		void Func3()
		{
			cout << "Base::Func3" << endl;
		}
	private:
		int _b = 1;
	};
	class Derive : public Base
	{
	public:
		virtual void Func1()
		{
			cout << "Derive::Func1()" << endl;
		}
		/*
		virtual void Func()
		{
			cout << "Derive::Func" << endl;
		}
		*/
	private:
		int _d = 2;//派生类对象中也有一个虚表指针，_d 的对象由两部分构成，一部分是父类继承下的成员
	};
}


namespace bit
{
	class Person
	{
	public:
		virtual void BuyTicket()
		{
			cout << "买票-全价" << endl;
		}
	};


	class Student : public Person
	{
	public:
		virtual void BuyTicket()
		{
			cout << "买票-半价" << endl;
		}
	};
	void Func(Person& p)
	{
		p.BuyTicket();
	}
}

int _main();
int __main();
int __main()
{
	bit::Person Mike;
	bit::Func(Mike);
	bit::Student Johson;
	bit::Func(Johson);
	return 0;
}
//静态多态与动态多态
//1. 静态绑定又称为前期绑定(早绑定)，在程序编译期间确定了程序的行为，也称为静态多态，比如：函数 重载 
//2. 动态绑定又称后期绑定(晚绑定)，是在程序运行期间，根据具体拿到的类型确定程序的具体行为，调用 具体的函数，也称为动态多
int _main()
{
	Person p;
	Student s;
	Func(p);
	Func(s);
	// 只有派生类Student的析构函数重写了Person的析构函数，
	//下面的delete对象调用析构函数，才能构成多 态，才能保证p1和p2指向的对象正确的调用析构函数。 
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	cout << sizeof(Base) << endl;
	Bit::Base b;
	Bit::Derive d;
	b.Func1();
	b.Func2();
	b.Func3();
	d.Func1();
	d.Func2();
	d.Func3();
	cout << "Bit::Base" << "->" << sizeof(Bit::Base) << endl;
	cout << "Bit::Derive" << "->" << sizeof(Bit::Derive) << endl;
	return 0;
}

/*
单继承中的虚函数表

*/

namespace base
{
	class Base
	{
	public:
		virtual void func1()
		{
			cout << "Base::func1()" << endl;
		}
		virtual void func2()
		{
			cout << "Base::func2()" << endl;
		}
	private:
		int _a;
	};
	class Derive : public Base
	{
	public:
		virtual void func1()
		{
			cout << "Derive::func1()" << endl;
			//cout << "Derive::func2()" << endl;
			//cout << "Derive::func3()" << endl;
		}
		virtual void func2()
		{
			cout << "Derive::func2()" << endl;
		}
		virtual void func3()
		{
			cout << "Derive::func3()" << endl;
		}
	private:
		int _b;
	};
	typedef void(*VFPTR)();
	void PrintVTable(VFPTR vTable[])
	{
		//依次取虚函数指针打印并调用。调用就可以看出存的是哪个函数

		cout << "虚表地址" << vTable << endl;
		for (int i = 0; vTable[i] != nullptr; ++i)
		{
			printf("第%d个虚函数地址 ：0x%x,->", i, vTable[i]);
			VFPTR f = vTable[i];
			f();
		}
		cout << endl;
	}

}

int main()
{
	base::Base b;
	base::Derive d;

	/*
	取出对象 b d 头的前四个字节，就是虚表的指针，前面我们说明了虚函数表本质是一个存放虚函数指针的指针数组，
	这个数组的最后面存放了一个 nullptr
	1、先取出 b 的地址，在强转成一个 int* 的指针
	2、然后解引用取值，就取到了 b 对象的头四个字节，这个值就是指向虚标的指针
	3、再强转成 VFPTR*，因为虚表就是一个存放 VFPTR* 类型的数组
	4、虚表指针传递给 PrintVTable 进行打印虚表
	*/
	base::VFPTR* vTableb = (base::VFPTR*)(*(int*)&b);   
	base::PrintVTable(vTableb);

	base::VFPTR* vTabled = (base::VFPTR*)(*(int*)&d); 
	base::PrintVTable(vTabled);

	return 0;
}