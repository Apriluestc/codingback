#include <iostream>
#include "SList.h"

ListNode* FindMidNode(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    ListNode* pSlow = pHead;
    ListNode* pFast = pHead;
    while(1)
    {
        pFast = pFast->m_pNext; //快的指针先走
        if(pFast == nullptr)    //快指针不为空再走一步
            break;
        pFast = pFast->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    cout << pSlow->m_Value << endl;
}
void FindMidNodeTest()
{
    cout << ">>查找链表的中间结点:" << endl;
    ListNode* pHead;
    SListInit(&pHead);
    SListPushBack(&pHead, 1);
    SListPushBack(&pHead, 3);
    SListPushBack(&pHead, 5);
    SListPushBack(&pHead, 7);
    SListPushBack(&pHead, 9);
    SListPushBack(&pHead, 2);
    SListPushBack(&pHead, 4);
    SListPushBack(&pHead, 6);
    SListPushBack(&pHead, 8);
    SListPrint(pHead);
    cout << FindMidNode(pHead) << endl;
}
int main()
{
    FindMidNodeTest();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

