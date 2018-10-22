#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL | head->next == NULL)
        {
            return head;
        }
        ListNode* pReverseNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return pReverseNode;
    }
};
int main()
{
    //std::cout << "Hello world" << std::endl;
    return 0;
}

