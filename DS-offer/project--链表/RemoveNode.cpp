/*************************************************************************
	> File Name: RemoveNode.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Oct 25 20:57:56 2018
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void RemoveNode(ListNode* *pHead, int value)
{
    if(pHead == NULL || *pHead == NULL)
    {
        return;
    }
    ListNode* pToBeDeleted = *pHead;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
        {
            pNode = pNode->m_pNext;

        }
        if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if(pToBeDeleted != NULL)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}


int main()
{
    return 0;
}
