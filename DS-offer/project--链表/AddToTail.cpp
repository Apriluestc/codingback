/*************************************************************************
	> File Name: AddToTail.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Oct 25 20:46:21 2018
 ************************************************************************/

#include<iostream>
using namespace std;
#include<assert.h>
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void AddToTail(ListNode* *pHead, int value)     /*函数的第一个参数是指向指针的指针,
                                       当链表为空时,申请的新结点就是该链表的头指针,
                                       因此头指针会发生变化,所以传入指针的指针,否则出了这个
                                       函数 pHead 就为一个空指针 */
{
    //申请新的结点
    ListNode* pNewNode = new ListNode();
    pNewNode->m_nValue = value;
    pNewNode->m_pNext = NULL;
    assert(pHead != NULL);
    if(*pHead == NULL)
    {
        *pHead = pNewNode;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNewNode;
    }
}
int main()
{
    return 0;
}
