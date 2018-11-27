#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

int gQuickSort[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 5, 4, 4 };
/*
题目：数组中有一个数字出现次数超过数组的一半，请找出这个数字；例如输入一个长度为 9 的
数组{1，2，3，2，2，2，4，5，2}，由于数字 2 出现了 5 次，超过数组的一半，因此输出为 2
*/

int MoreThanHalfNum(int array[], int length)
{
	if (array == nullptr || length <= 0)
	{
		return 0;
	}
	int result = array[0];//返回结果 result ，初始值用 array[0] 进行初始化
	int i = 0;
	int times = 1;//初始值任意一个数字出现次数为 1
	for (i = 1; i < length; ++i)
	{
		if (times == 0)//只有当出现次数为 0 时，result 才会赋新值
		{
			result = array[i];
			times = 1;
		}
		else if (result == array[i])//当保存的值与遍历数组当中的值相等时 times 才会 ++
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	return result;
}
void TestArray()
{
	//不修改数组，仅仅遍历一遍数组记录每个数字跟它出现的次数；前提输入的数组符合要求
	int array[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int length = sizeof(array) / sizeof(array[0]);
	cout << MoreThanHalfNum(array, length) << setw(4) << endl;
}
//二分查找（折半查找）
int Binary_search(int array[], int length, int key)
{
	int left = 0;
	int right = length - 1;
	int result = -1;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (array[mid]==key)
		{	
			result = key;
			break;
		}
		if (array[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return result;
}
void TestBinary_search()
{
	int array[] = { 1, 2, 3, 2, 2, 2, 4, 5, 2 };
	int length = sizeof(array) / sizeof(array[0]);
	cout << Binary_search(array, length, 3) << endl;
	cout << Binary_search(array, length, 7) << endl;
}

//判断数据的合法性
bool g_bInputInvalid = false;
bool CheckInvalidArray(int array[], int length)
{
	g_bInputInvalid = false;
	if (array == NULL || length <= 0)
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}
int get_middle(int array[], int start, int end);
//寻找基准数分别对左边和右边进行排序
void quick_sort(int array[], int length, int start, int end)
{
	CheckInvalidArray(array, length);
	int middle;
	if (start >= end)
		return;
	middle = get_middle(array, start, end);
	quick_sort(array, length, start, middle - 1);
	quick_sort(array, length, middle + 1, end);
}
//获取中间基准数
int get_middle(int array[], int start, int end)
{
	int front = 0;
	int tail = end - start;
	int value = array[start];
	int length = end - start + 1;
	int loop = start + 1;

	while (loop <= end){
		if (array[loop] < value){
			gQuickSort[front] = array[loop];
			front++;
		}
		else{
			gQuickSort[tail] = array[loop];
			tail--;
		}

		loop++;
	}
	gQuickSort[front] = value;
	memmove(&array[start], gQuickSort, sizeof(int)* (length));
	return start + front;
}
//快排的三个步骤
/*
1、首先判断数据的合法性
2、寻找中间数，分别对左边和右边数据进行排序
3、设置中间数
*/

void _quicksort(int array[], int length, int start, int end)
{
	int i, j;

	if (start < end)
	{
		i = start + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
		j = end;        // array[end]是数组的最后一位
		while (i < j)
		{
			if (array[i] > array[start])  // 如果比较的数组元素大于基准数，则交换位置。
			{
				swap(array[i], array[j]);  // 交换两个数
				j--;
			}
			else
			{
				i++;  // 将数组向后移一位，继续与基准数比较。
			}
		}

		/* 跳出while循环后，i = j。
		* 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin]
		*                           -->  array[i+1] ~ array[end] > array[begin]
		* 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。
		* 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
		*/

		if (array[i] >= array[start])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
		{
			i--;
		}

		//swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]
		swap(array[i], array[start]);
		_quicksort(array, length, start, i);
		_quicksort(array, length, j, end);
	}