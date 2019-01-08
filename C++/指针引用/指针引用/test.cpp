#include "User.h"
#include <string.h>
int main()
{
	char *p = NULL;//设置指针为空值
	char &r = *p;//让引用指向空值 X
	//这样做非常有害，执行结果是不确定的
	string a = "1";
	string& rs = a;//假如引用未初始化引用必须初始化 X
	string s("simon");
	string &rs = s;//正确，rs指向s

	string *p = nullptr;//假如使用未初始化的指针，虽说能编译通过，但是存在风险 
	return 0;
}