#include <iostream>
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* MeetNode(ListNode* pHead)
{
    if(pHead == NULL)
    {
        return NULL;
    }
    ListNode* pFast = pHead->m_pNext;
    ListNode* pSlow = pSlow->m_pNext;
    while(pFast != NULL && pSlow != NULL && pFast != pSlow)
    {
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext->m_pNext;
    }
    return pFast;
}
ListNode* meetNode(ListNode* pHead)
{
    if(pHead == NULL)
    {
        return NULL;
    }
    ListNode* pSlow = pHead->m_pNext;
    if(pSlow == NULL)
    {
        return NULL;
    }
    ListNode* pFast = pSlow->m_pNext;
    if(pFast == NULL)
    {
        return NULL;
    }
    while(pFast != NULL && pSlow != NULL)
    {
        if(pFast == pSlow)
        {
            return pFast;
        }
        pFast = pFast->m_pNext;
        pSlow = pSlow->m_pNext;
        if(pFast != NULL)
        {
            pFast = pFast->m_pNext;
        }
    }
    return NULL;
}
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* pMeetNode = meetNode(pHead);
    if(pMeetNode == NULL)
    {
        return NULL;
    }
    //得到环中节点数目
    int count = 1;
    ListNode* pNode = pMeetNode;
    while(pNode->m_pNext != pMeetNode)
    {
        pNode = pNode->m_pNext;
        ++count;
    }
    //先移动快指针
    ListNode* pNode1 = pHead;
    for(int i = 0; i < count; i++)
    {
        pNode1 = pNode1->m_pNext;
    }
    //快慢指针一起移动
    ListNode* pNode2 = pHead;
    while(pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;
}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

