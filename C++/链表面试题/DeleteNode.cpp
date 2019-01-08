#include <iostream>
#include "SList.h"
void DeleteNode(ListNode** pHead, ListNode* pToDeleted)
{
    //删除链表的结点
    if(pHead == nullptr || pToDeleted == nullptr)
        return ;
    //要删除不是尾节点
    if(pToDeleted->m_pNext != nullptr)
    {
        ListNode* pNext = pToDeleted->m_pNext;
        pToDeleted->m_Value = pNext->m_Value;
        pToDeleted->m_pNext = pNext->m_pNext;
        delete pNext;
        pNext = nullptr;
    }
    //链表只有一个结点
    else if(pToDeleted == *pHead)
    {
        delete pToDeleted;
        pToDeleted = nullptr;
        *pHead = nullptr;
    }
    //链表中有多个节点
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = nullptr;
        delete pToDeleted;
        pToDeleted = nullptr;
    }
}

void DeleteNodeTest()
{
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
    SListPrint(pHead);
    DeleteNode(&pHead, (ListNode*)3);
    SListPrint(pHead);
}
int main()
{
    DeleteNodeTest();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

