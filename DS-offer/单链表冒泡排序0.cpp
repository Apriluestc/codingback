#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

struct ListNode
{
	int m_Value;
	struct ListNode *m_pNext;
};
class Solution
{
public:
	ListNode * Pop(ListNode *pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode *pTail = NULL;
		while (pTail != pHead->m_pNext)
		{
			ListNode *pPrev = pHead;
			int temp;
			ListNode *Cur = pPrev;
			while (Cur != pTail && Cur->m_pNext != pTail)
			{
				if (Cur->m_Value > Cur->m_pNext->m_Value)
				{
					temp = Cur->m_Value;
					Cur->m_Value = Cur->m_pNext->m_Value;
					Cur->m_pNext->m_Value = temp;
				}
				pPrev = pPrev->m_pNext;
				Cur = Cur->m_pNext;
			}
			pTail = Cur;
		}
		return pHead;
	}
};

int main()
{
	return 0;
}