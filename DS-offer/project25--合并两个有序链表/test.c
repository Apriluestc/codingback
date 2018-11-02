#include <stdio.h>
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
    {
        return pHead2;
    }
    if(pHead2 == NULL)
    {
        return pHead1;
    }
    ListNode* pMergeListNode = NULL;
    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergeListNode = pHead1;
        pMergeListNode->m_pNext = MergeList(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergeListNode = pHead2;
        pMergeListNode = MergeList(pHead1, pHead2->m_pNext);
    }

    return pMergeListNode;
}
int main()
{
    printf("Hello world\n");
    return 0;
}

