/*************************************************************************
	> File Name: test1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Oct 25 20:00:20 2018
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead->m_pNext != NULL)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        printf("%d\t", pHead->m_nValue);
    }
}
int main()
{
    return 0;
}
