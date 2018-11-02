#include <iostream>
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* ReversList(ListNode* pHead)
{
    if(pHead == NULL)
    {
        return NULL;
    }
    ListNode* pReversedHead = ReversList(pHead->m_pNext);
    pHead->m_pNext->m_pNext = pHead;
    pHead->m_pNext = NULL;
    return pReversedHead;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

