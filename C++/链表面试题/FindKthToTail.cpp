#include "SList.h"


/*
* struct ListNode
{
    DataType m_Value;
    ListNode* m_pNext;
};
*/

ListNode* __FindKthToTail(ListNode* pHead, unsigned int k)
{
    if(pHead == nullptr || k == 0)
        return nullptr;
    ListNode* pFast = pHead;
    ListNode* pSlow = pHead;
    for(unsigned int i = 0; i < k-1; ++i)
    {
        if(pFast->m_pNext != nullptr)
        {
            pFast = pFast->m_pNext;
        }
        else
        {
            return nullptr;
        }
    }
    while(pFast->m_pNext != nullptr)
    {
        pSlow = pSlow->m_pNext;
    }
    return pSlow;
}
ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
    if(pHead == nullptr || k == 0)
        return nullptr;
    ListNode* pFast = pHead;
    ListNode* pSlow = pHead;
    while(--k && pFast->m_pNext != nullptr)
        pFast = pFast->m_pNext;
    while(pFast->m_pNext != nullptr)
    {
        pFast = pFast->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    cout << pSlow->m_Value << endl;
    return pSlow;
}

void FindKthToTailTest()
{
    cout << ">>查找链表倒数第 K 个结点" << endl;
    ListNode* pHead;
    SListInit(&pHead);
    SListPushBack(&pHead, 1);
    SListPushBack(&pHead, 2);
    SListPushBack(&pHead, 4);
    SListPushBack(&pHead, 7);
    SListPushBack(&pHead, 3);
    SListPushBack(&pHead, 5);
    SListPushBack(&pHead, 9);
    SListPushBack(&pHead, 8);
    SListPushBack(&pHead, 12);
    cout << "倒数第 3 个结点 : " << FindKthToTail(pHead, 3) << endl;
    SListPrint(pHead);
}
/*
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k == 0)
            return nullptr;
        int len = 0;
        ListNode* pCur = pListHead;
        while(pCur)
        {
            len++;
            pCur = pCur->next;
        }
        if(k > len)
            return nullptr;
        
        ListNode* pFast = pListHead;
        ListNode* pSlow = pListHead;
        while(--k && pFast->next)
            pFast = pFast->next;
        while(pFast->next)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
}
*/
void __FindKthToTailTest()
{
    cout << ">>优化版本：" << endl;
    cout << ">>查找链表倒数第 K 个结点:" << endl;
    ListNode* pHead;
    SListInit(&pHead);
    SListPushBack(&pHead, 1);
    SListPushBack(&pHead, 2);
    SListPushBack(&pHead, 4);
    SListPushBack(&pHead, 7);
    SListPushBack(&pHead, 3);
    SListPushBack(&pHead, 5);
    SListPushBack(&pHead, 9);
    SListPushBack(&pHead, 8);
    SListPushBack(&pHead, 12);
    cout << "倒数第 3 个结点 : " << __FindKthToTail(pHead, 3) << endl;
    SListPrint(pHead); 
}
int main()
{
    FindKthToTailTest();
    __FindKthToTailTest();
    return 0;
}
