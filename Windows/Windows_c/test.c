#define _CRT_SECURE_NO_WARNINGS 1
//添加赋值运算符函数
#include<iostream>
using namespace std;
class CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString &str);
	~CMyString(void);
private:
	char *m_pData;
};
CMyString & CMyString::operator=(const CMyString &str)
{
	if (this != str)
	{
		CMyString strTemp(str);
		char *pTemp = strTemp.m_pData;
		StrTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}
//找数组中重复出现的数字
bool duplicate(int numbers[], int length, int *duplication)
{
	if (numbers == NULL || length < 0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}
	for (int i = 0; i < length; ++i)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}
//不修改数组，找重复出现的数字
int getDuplication(const int * numbers, int length)
{
	if (numbers == NULL || length < 0)
		return -1;
	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, lenth, start, middle);
		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}
		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
			start = middle + 1;
	}
	return -1;
}
int countRange(const int * numbers, int length, int start, int end)
{
	if (numbers == NULL)
		return 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}
	return count;
}
//二维数组的查找
bool Find(int *matrix, int rows, int cols, int numbers)
{
	bool found = false;
	if (matrix != NULL && rows > 0 && clos > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (matrix[row * cols + col] == numbers)
			{
				found = true;
				break;
			}
			else if (matrix[row * cols + col] > numbers)
			{
				--col;
			}
			else
				++row
		}
	}
	return found;
}
//
int main()
{
	return 0;
}