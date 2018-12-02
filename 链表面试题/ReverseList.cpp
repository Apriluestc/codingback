#include "SList.h"

ListNode* ReverseList(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    if(pHead->m_pNext == nullptr)
        return pHead;
    ListNode* pCur = pHead->m_pNext;
    ListNode* pPrev = pHead;
    ListNode* pNext = pCur->m_pNext;
    while(pCur->m_pNext != nullptr)
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

