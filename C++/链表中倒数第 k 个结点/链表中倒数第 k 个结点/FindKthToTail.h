#pragma once
#include <iostream>
#include <list>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
};

ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
	if (pHead == nullptr || k == 0)
		return nullptr;
	ListNode* pFast = pHead;
	ListNode* pSlow = pHead;
	while (--k)
	{
		if (pFast->next != nullptr)
		{
			pFast = pFast->next;
		}
		else
		{
			return nullptr;
		}
	}
	while (pFast->next)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}
void FindKthToTailTest()
{
	list<int> result;
	result.push_back(1);
	result.push_back(3);
	result.push_back(4);
	result.push_back(2);
	result.push_back(5);
	result.push_back(7);
	result.push_back(8);
	result.push_back(9);
	cout << result._Myval << " " << endl;
}