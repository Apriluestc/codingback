#include <iostream>
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
/* 查找链表倒数第 k 个结点 */
ListNode* FindKthToTail(ListNode* pHead, unsigned int k)
{
    if(pHead == NULL || k == 0)
    {
        return NULL;
    }
    ListNode* pAhead = pHead;   //定义快指针 pAhead 让其先走 k - 1 步
    ListNode* pBehind = NULL;   
    /*定义慢指针 pBehind 当快指针走完 k - 1 步时
     * 二者一起走,到快指针的下一个指针为空时停止*/
    for(unsigned int i = 0; i < k - 1; ++i)
    {
        if(pAhead->m_pNext != NULL)
        {
            pAhead = pAhead->m_pNext;
        }
        else
        {
            return NULL;
        }
    }//k小于链表节点数目,否则返回 NULL
    pBehind = pHead;    //  慢指针从头开始走
    while(pAhead->m_pNext != NULL)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }
    return pBehind;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

