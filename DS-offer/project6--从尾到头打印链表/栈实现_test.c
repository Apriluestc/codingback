/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Oct 25 19:51:35 2018
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stack>
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    stack<ListNode *> nodes;
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

int main()
{
    return 0;
}
