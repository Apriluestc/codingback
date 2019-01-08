#include <iostream>
#include "SList.h"
/*
 * 找两个链表的公共结点
 * 1、分别计算两个链表的长度
 * 2、比较两个链表哪一个较长，长多少，较长的那一个就先走多少
 * 3、让两个链表g同步往后走，相遇点即链表公共节点:wq
 *
 * */
ListNode* FindSameNode(ListNode* pHead1, ListNode* pHead2)
{
    size_t len1 = 0;
    size_t len2 = 0;
    if(pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;

    ListNode* pCur1 = pHead1;
    ListNode* pCur2 = pHead2;
    int sublen = 0;
    while(pCur1)//获取链表 1 的长度
    {
        len1++;
        pCur1 = pCur1->m_pNext;
    }
    while(pCur2)//获取链表 2 的长度
    {
        len2++;
        pCur2 = pCur2->m_pNext;
    }
    pCur1 = pHead1;
    pCur2 = pHead2;
    if(len1 < len2)
    {
        sublen = len2 - len1;
        while(sublen--)
        {
            pCur2 = pCur2->m_pNext;
        }
    }
    //pCur1 = pHead1;
    //pCur2 = pHead2;
    if(len1 > len2)
    {
        sublen = len1 - len2;
        while(sublen--)
        {
            pCur1 = pCur1->m_pNext;
        }
    }

    while(pCur1 != nullptr || pCur2 != nullptr)
    {
        if(pCur1->m_Value == pCur2->m_Value)
            break;
        pCur1 = pCur1->m_pNext;
        pCur2 = pCur2->m_pNext;
    }
    return pCur1;
}

void FindSameNodeTest()
{
    cout << "查找两个链表的公共结点" << endl;
    ListNode* pHead1;
    ListNode* pHead2;
    //SListInit(&pHead1);
    //SListInit(&pHead2);
    SList(pHead1);
    SList(pHead2);
    cout << FindSameNode(pHead1, pHead2) << endl;
}
int main()
{
    FindSameNodeTest();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

