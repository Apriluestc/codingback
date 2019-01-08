#include <iostream>
#include "user.h"
#include <cstdlib>
using namespace std;

const char*fileDat = "c:/StudentDates";

int main()
{
	char choice;
	while (1)
	{
		system("cls");
		cout << "**********************************************" << endl;
		cout << "*                 学生信息管理系统           *" << endl;
		cout << "**********************************************" << endl;
		cout << "*               1：录入成绩                  * " << endl;
		cout << "*               2：成绩浏览                  * " << endl;
		cout << "*               3：查询成绩                  * " << endl;
		cout << "*               4: 修改成绩                  * " << endl;
		cout << "*               5: 成绩补录                  *" << endl;
		cout << "*               6: 删除数据                  *" << endl;
		cout << "*               7: 学生排序                  *" << endl;
		cout << "*               q: 退出程序                  * " << endl;
		cout << "**********************************************" << endl;
		cout << "请输入您的选择:";
		cin >> choice;
		switch (choice)
		{
		case'1':Input(fileDat); break;
		case'2':Inquire(fileDat); break;
		case'3':Change(fileDat); break;
		case'4':Modify(fileDat); break;
			//		case'5':Add(fileDat);break;
		case'6':Delete(fileDat); break;
		case'7':Stusort(fileDat); break;
		case'q':
		case'Q':cout << "退出系统\n"; return 0;
			//		default:cout<<"输入错误，请再输入";
		}
	}
}

