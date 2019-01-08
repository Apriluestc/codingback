#include <iostream>

using namespace std;

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

//节点结构体
typedef struct ListNode
{
	DataType m_Value;
	struct ListNode* m_pNext;
}ListNode;

void SListInit(ListNode* *p)
{
	assert(p != NULL);
	*p = nullptr;

}
static ListNode* CreatNode(DataType m_Value)
{
	ListNode* pNode = (ListNode *)malloc(sizeof(ListNode));
	pNode->m_Value = m_Value;
	pNode->m_pNext = NULL;
	return pNode;
}

void SListPushBack(ListNode* *p, DataType m_Value)
{
	ListNode* pNode = CreatNode(m_Value);/* 申请节点，赋值且插入 */
	assert(p != NULL);//传入地址不为空
	if (*p == NULL)/* 链表为空 */
	{
		*p = pNode;
		return;
	}
	//找链表中的最后一个节点
	//ListNode* pNode = CreatNode(m_Value);//申请节点，赋值且插入
	ListNode* cur = *p;
	while (cur->m_pNext != NULL)
	{
		cur = cur->m_pNext;
	}
	cur->m_pNext = pNode;
}

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	if (pHead->m_pNext == nullptr)
		return pHead;
	ListNode* pCur = pHead->m_pNext;
	ListNode* pPrev = pHead;
	ListNode* pNext = pCur->m_pNext;
	while (pCur->m_pNext != nullptr)
	{
		pNext = pCur->m_pNext;//保存链表结点要断开的n下一个节点
		pCur->m_pNext = pPrev;//当前指针的下一个指向它的前驱
		pPrev = pCur;//q前驱、当前结点往后移动
		pCur = pNext;
	}
	pCur->m_pNext = pPrev;//最后一个节点指向它的前驱
	pHead->m_pNext = nullptr;//最后一个节点的下一个结点置 nullptrptr
	return pCur;
}

void SListPrint(ListNode* p)
{
	ListNode* cur = p;
	while (cur != NULL)
	{
		printf("%d ", cur->m_Value);
		cur = cur->m_pNext;
	}
	printf("\n");
}
void ReverseListTest()
{
	cout << ">>反转链表" << endl;
	ListNode* pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 9);
	//cout << "反转前的链表" << endl;
	SListPrint(pHead);
	//ReverseList(pHead);
	//cout << "反转后的链表" << endl;
	SListPrint(ReverseList(pHead));

	//ReverseList(pHead);
	//SListPrint(pHead);
}
int main()
{
	ReverseListTest();
	//std::cout << "Hello world" << std::endl;
	return 0;
}
