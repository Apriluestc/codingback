#if 0

#include <iostream>
using namespace std;

//懒汉模式：懒汉模式的特点是延迟加载，比如配置文件，采用懒汉式的方法
//顾名思义，懒汉么，很懒的，配置文件的实例直到用到的时候才会加载
//不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化
//静态指针 + 用到时初始化
template<class T>
class Singleton
{
public:
	static T& GetInstance()
	{
		if (!_value)
		{
			_value = new T();
		}
		return *_value;
	}
private:
	Singleton()
	{}
	~Singleton()
	{}
	static T* _value;
};
template<class T>
T* Singleton<T>::_value = NULL;

// 在单线程中，这样的写法是可以正确使用的，但是在多线程中就不行了，该方法是线程不安全的。
//（1）假如线程A和线程B, 这两个线程要访问getInstance函数，线程A进入getInstance函数
//并检测if条件，由于是第一次进入，value_为空，if条件成立，准备创建对象实例。
//（2）但是，线程A有可能被OS的调度器中断而挂起睡眠，而将控制权交给线程B。
//（3）线程B同样来到if条件，发现value_还是为NULL，因为线程A还没来得及构造它就已经被中断了。
//此时假设线程B完成了对象的创建，并顺利的返回。
//（4）之后线程A被唤醒，继续执行new再次创建对象，这样一来，两个线程就构建两个对象实例，这就破坏了唯一性。
//另外，还存在内存泄漏的问题，new出来的东西始终没有释放，下面是一种饿汉式的一种改进

namespace bat
{
	template<class T>
	class Singleton
	{
	public:
		static T& GetInstance()
		{
			if (!_value)
			{
				_value = new T();
			}
			return *_value;
		}
	private:
		class CGarbo
		{
		public:
			~CGarbo()
			{
				if (Singleton::_value)
					delete Singleton::_value;
			}
		};
		static CGarbo Garbo;
		Singleton();
		~Singleton();
		static T* _value;
	};
	template<class T>
	T* Singleton<T>::_value = NULL;
}

namespace bat1
{
	template<class T>
	class Singleton
	{
	public:
		static T& GetInstance()
		{
			static T instance;
			return instance;
		}

	private:
		Singleton()
		{}
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);
	};

}
int main()
{
	return 0;
}

#endif

#include <string>
#include <iostream>
using namespace std;
class Log
{
public:
	static Log* GetInstance()
	{
		static Log oLog;
		return &oLog;
	}

	void Output(string strLog)
	{
		cout << strLog << (*m_pInt) << endl;
	}
private:
	Log() :m_pInt(new int(3))
	{
	}
	~Log()
	{
		cout << "~Log" << endl;
		delete m_pInt;
		m_pInt = NULL;
	}
	int* m_pInt;
};

class Context
{
public:
	static Context* GetInstance()
	{
		static Context oContext;
		return &oContext;
	}
	~Context()
	{
		Log::GetInstance()->Output(__FUNCTION__);
	}

	void fun()
	{
		Log::GetInstance()->Output(__FUNCTION__);
	}
private:
	Context(){}
	Context(const Context& context);
};

int main(int argc, char* argv[])
{
	Context::GetInstance()->fun();
	return 0;
}
