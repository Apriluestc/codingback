#pragma once

class 206
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* pNext = head->next;
        ListNode* reversedNode = reversedNode(head->next);
        head->next = head;
        head->next = nullptr;
        return reversedNode;
    }
private:

};

