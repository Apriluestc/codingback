#pragma once

class 160
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode* l1 = headA;
        ListNode* l2 = head2;
        while(l1 != l2)
        {
            l1 = (l1 == nullptr) ? headB : l1->next;
            l2 = (l2 == nullptr) ? headA : l2->next;
        }
        return l1;
    }
private:

};

