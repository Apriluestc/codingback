#include <stdio.h>
struct Student
{
	int number;
	char* name;
	char* sex;
	int age;
	char* deptno;
};
struct Student student;
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;
Date date;
int main()
{
	date.year = 2018;
	date.month = 1;
	date.day = 1;
	student.name = "Tom";
	student.age = 20;
	student.number = 0110;
	student.deptno = "ÊıÑ§Ïµ";
	student.sex = "ÄĞ";
	return 0;
}