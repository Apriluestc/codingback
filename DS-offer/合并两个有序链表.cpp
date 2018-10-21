/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
       else if(pHead2==NULL)
            return pHead1;
         
         ListNode* newhead=NULL;
        
        if(pHead1->val<pHead2->val)
                 
           {
              newhead=pHead1;
              newhead->next=Merge(pHead1->next,pHead2);
          }
           else
               {
               newhead=pHead2;
              newhead->next=Merge(pHead1,pHead2->next);
           }
       return newhead;
    }
};