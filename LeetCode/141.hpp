#pragma once

class 141
{
public:
    bool hasCycle(ListNode* head)
    {
        if(head == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(slow != NULL && fast != NULL && fast->next != NULL)
        {
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

