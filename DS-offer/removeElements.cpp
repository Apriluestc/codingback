#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};
ListNode* removeElements(ListNode* head, int val)
{
    if(head == NULL)
    {
        return NULL;
    }
    ListNode* prev = head;
    ListNode* cur = head->next;
    while(cur != NULL)
    {
        if(cur->val == val)
        {
            prev->next = cur->next;
            cur = cur->next;
        }
        else
        {
            prev->next = cur;
            cur = cur->next;
        }
    }
    if(head->val == val)
    {
        head = head->next;
    }
    return head;
}
int main()
{

    //std::cout << "Hello world" << std::endl;
    return 0;
}

