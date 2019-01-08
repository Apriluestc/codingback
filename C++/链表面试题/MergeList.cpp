#include <iostream>
#include "SList.h"
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
    //cout << "合并两个有序链表" << endl;
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;
    if(pHead1 == nullptr && pHead2 == nullptr)
        return nullptr;
    ListNode* pMergeListNode = nullptr;   
    if(pHead1->m_Value <= pHead2->m_Value)
    {
        pMergeListNode = pHead1;
        pMergeListNode->m_pNext = MergeList(pHead1->m_pNext, pHead2);
    }
    if(pHead1->m_Value > pHead2->m_Value)
    {
        pMergeListNode = pHead2;
        pMergeListNode->m_pNext = MergeList(pHead1, pHead2->m_pNext);
    }
    return pMergeListNode;
}
void MergeListTest()
{
    cout << ">>合并两个有序链表" << endl;
    ListNode* pHead1;
    ListNode* pHead2;
    SListInit(&pHead1);
    SListInit(&pHead2);
    SListPushBack(&pHead1, 1);
    SListPushBack(&pHead1, 2);
    SListPushBack(&pHead1, 5);
    SListPushBack(&pHead1, 7);
    SListPushBack(&pHead1, 8);
    SListPushBack(&pHead2, 2);
    SListPushBack(&pHead2, 3);
    SListPushBack(&pHead2, 4);
    SListPushBack(&pHead2, 0);
    SListPushBack(&pHead2, 9);
    cout << "pHead1:" << endl;
    SListPrint(pHead1);
    //SListPrint(pHead2);
    cout << "pHead2:" << endl;
    SListPrint(pHead2);
    SListPrint(MergeList(pHead1, pHead2));
    cout << endl;
    
}

int main()
{
    MergeListTest();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

