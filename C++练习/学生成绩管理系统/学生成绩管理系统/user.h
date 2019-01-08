#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
struct student
{
	int number;
	char name[40];
	char sex[4];
	int score[3];
	int avg;

};
bool GreaterSort(student a, student b);
ostream &operator<<(ostream &os, student a);
void Input(const char*fileDat);
void Inquire(const char*fileDat);
int Change(const char*fileDat);
void Modify(const char*fileDat);
void Search(const char*fileDat);
void Delete(const char*fileDat);
void Add(const char*fileDat);
void Modify(const char*fileDat);
void Stusort(const char*fileDat);
bool Search(const char*fileDat, int num);
int endMark(student stu);
