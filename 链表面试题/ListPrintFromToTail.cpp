#include "SList.h"
#include <iostream>
#include <stack>
ListNode* ListPrintFronToTail(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    stack<ListNode*> nodes;
    ListNode* pCur = pHead;
    while(pCur->m_pNext != nullptr)//链表不为空入栈，直到当前结点的下一个结点是 nullptr
    {
        nodes.push(pCur);
        pCur = pCur->m_pNext;
    }
    //cout << "从尾到头打印的链表为:" << endl;
    //ListNode* p = nullptr;
    while(!nodes.empty())//栈不为空出栈
    {
        pCur = nodes.top();
        //cout << "从尾到头打印的链表为:" << endl;
        cout << pCur->m_Value << " ";
        nodes.pop();
    }
    cout << endl;
}

void ListPrintFronToTailTest()
{
    cout << ">>从尾到头打印链表" << endl;
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
    ListPrintFronToTail(pHead);
    //std::cout << "Hello world" << std::endl;
    //return 0;
}
int main()
{
    ListPrintFronToTailTest();
    return 0;
}

