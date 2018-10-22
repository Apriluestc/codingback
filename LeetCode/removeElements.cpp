#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};

class Solution{
public:
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
            if(val == cur->val)
            {
                prev->next = cur->next;
                cur = cur->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        if(val = head->val)
        {
            head = head->next;
        }

        return head;
    }
};
int main()
{
    //std::cout << "Hello world" << std::endl;
    return 0;
}

