/* 学生成绩管理系统功能函数 student.cpp */

#include "user.h"

//查询
#include <cstring>
int Change(const char*fileDat)
{
	ifstream fin;
	fin.open(fileDat);
	if (!fin.is_open())
	{ 
		cout << "文件打开失败"; 
	}
	else 
	{
		cout << "1:按学号查询\n2:按姓名查询\n";
		int n;
		cin >> n;

		if (n == 1){
			int num;
			cout << "输入要查询的学号：";
			cin >> num;
			student stu;
			while (fin.read((char*)&stu, sizeof stu))
			{
				if (stu.number == num)
				{
					num = 0;
					cout << stu.number << "\t" << stu.name << "\t" << stu.sex << "\t" << stu.score[0] << "\t" << stu.score[1] << "\t" << stu.score[2] << "\t" << endl;
					break;
				}
			}
			if (num != 0)
			{
				cout << "没有发现你输入的学号\n";
				fin.close();
				system("pause");
				return 0;
			}
		}
		else
		{
			char name[40];
			cout << "输入要查询的学生姓名：";
			cin >> name;
			int num = 1;
			student stu;
			while (fin.read((char*)&stu, sizeof stu)) 
			{
				if (!strcmp(name, stu.name))
				{
					num = 0;
					cout << stu.number << "\t" << stu.name << "\t" << stu.sex << "\t" << stu.score[0] << "\t" << stu.score[1] << "\t" << stu.score[2] << "\t" << endl;
					break;
				}
			}
			if (num != 0)
			{
				cout << "没有发现你输入的姓名学生\n";
				fin.close();
				system("pause");
				return 0;
			}

		}
	}
	fin.close();
	system("pause");
	return 1;



}

//删除


#include <fstream>

ostream &operator<<(ostream &os, student a){ os << a.name; return os; }

void Delete(const char*fileDat)
{
	vector <student> vec;
	ifstream fin;
	fin.open(fileDat);
	if (!fin.is_open())
	{
		cout << "文件打开失败"; 
	}
	else
	{
		student stu;
		while (fin.read((char *)&stu, sizeof stu))
		{

			stu.avg = (stu.score[0] + stu.score[1] + stu.score[2]) / 3;
			vec.push_back(stu);
		}
		fin.close();
		int num;
		cout << "输入要删除的学号：";
		cin >> num;

		if (Search(fileDat, num))
		{
			vector<student>::iterator  it = vec.begin();

			for (; it != vec.end(); it++)
			{
				if (it->number == num)
				{
					vec.erase(it);
					cout << "删除成功！";
					break;
				}
			}



			ofstream fout;
			fout.open(fileDat, ios_base::binary);
			if (!fout.is_open())
			{
				cout << "文件打开失败！"; 
			}
			else
			{
				for (auto it = vec.begin(); it != vec.end(); it++)
				{

					fout.write((char *)&*it, sizeof stu);
				}
				fout.close();

			}

		}
		else
		{
			cout << "学号不存在！\n"; 
		}
	}




	system("pause");
}

//插入记录
void Input(const char*fileDat)
{
	ofstream fout;




	student stu;
	cout << "输入学生学号，学号为0表示结束输入：";
	cin >> stu.number;


	while (stu.number != 0)
	{
		if (Search(fileDat, stu.number)) cout << "此学号已经存在重新输入！\n";
		else
		{


			cout << "输入学生姓名:";
			cin >> stu.name;
			cout << "输入学生性别:";
			cin >> stu.sex;
			cout << "输入学生三科成绩:";
			cin >> stu.score[0] >> stu.score[1] >> stu.score[2];




			fout.open(fileDat, ios_base::out | ios_base::app | ios_base::binary);
			if (!fout.is_open())
			{
				cout << "打开文件失败！!"; 
				fout.close();
				break;
			}
			else
				fout.write((char *)&stu, sizeof(stu));
			fout.close();
		}
		cout << "输入学生学号，学号为0表示结束输入：";
		cin >> stu.number;
	}
	system("pause");
}
//查询学生信息
#include <cstdlib>
using namespace std;
void Inquire(const char*fileDat)
{
	ifstream fin;
	fin.open(fileDat);
	if (!fin.is_open())
	{
		cout << "文件打开失败！"; 
	}
	else
	{
		student stu;
		while (fin.read((char *)&stu, sizeof(stu)))
		{
			cout << stu.number << "\t" << stu.name << "\t" << stu.sex << "\t" << stu.score[0] << "\t" << stu.score[1] << "\t" << stu.score[2] << "\t" << endl;
		}

	}
	fin.close();
	system("pause");

}
//修改数据功能


void Modify(const char*fileDat)
{
	int  gps;
	ifstream fin;
	fin.open(fileDat, ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cout << "文件打开失败"; 
	}
	else
	{
		int num;
		cout << "输入要修改的学号：";
		cin >> num;
		student stu;

		while (!fin.eof())
		{
			gps = (int)fin.tellg();
			cout << "编号" << gps << endl;
			fin.read((char *)&stu, sizeof stu);
			if (stu.number == num)
			{
				cout << stu.number << "\t" << stu.name << "\t" << stu.sex << "\t" << stu.score[0] << "\t" << stu.score[1] << "\t" << stu.score[2] << "\t" << endl;
				fin.close();
				break;
			}
		}

		if (fin.is_open())
		{
			cout << "没有找到此编号！"; 
			fin.close(); 
		}

		else {
			cout << "输入修改后的三科成绩：";
			cin >> stu.score[0] >> stu.score[1] >> stu.score[2];

			fstream fout;
			fout.open(fileDat, ios_base::in | ios_base::out | ios_base::binary);
			if (!fout.is_open())
			{
				cout << "文件打开失败！"; 
			}
			else
			{
				if (gps != 0)fout.seekp(gps);
				fout.write((char *)&stu, sizeof stu);
				cout << "修改成功！";
				fout.close();
			}

		}

	}


	system("pause");

}

//搜索
bool Search(const char*fileDat, int num)
{

	ifstream fin(fileDat, ios_base::in | ios_base::binary);
	if (!fin.is_open()) cout << "文件打开失败";
	else
	{
		student stu;
		while (fin.read((char *)&stu, sizeof stu))
		if (stu.number == num)
		{
			fin.close();
			return true; 
		}
	}

	fin.close();
	return false;

}

//排序
bool GreaterSort(student a, student b)
{
	return a.avg>b.avg;
}

void Stusort(const char*fileDat){

	vector <student> vec;
	ifstream fin;
	fin.open(fileDat);
	if (!fin.is_open())
	{
		cout << "文件打开失败"; 
		fin.close();
	}
	else
	{
		student stu;
		while (fin.read((char *)&stu, sizeof stu))
		{
			stu.avg = (stu.score[0] + stu.score[1] + stu.score[2]) / 3;
			vec.push_back(stu);
		}

		fin.close();
		sort(vec.begin(), vec.end(), GreaterSort);
		ofstream fout;
		fout.open(fileDat);
		if (!fout.is_open())
		{
			cout << "文件打开失败！"; 
			fout.close();
		}
		else
		{
			for (auto it = vec.begin(); it != vec.end(); it++)
			{
				fout.write((char *)&*it, sizeof stu);
			}
			fout.close();

		}
	}
	cout << "排序完成！\n";
	system("pause");

}
