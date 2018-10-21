#include <iostream>
using namespace std;
#include<vector>
#include<iomanip>
struct ListNode
{
    int val;
    ListNode* next;
};
ListNode* ReverseList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* pReverseNode = ReverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return pReverseNode;
}
int main()
{
    //vector<vector<int> > buffer[8];
    //for(size_t i = 0; i < sizeof(buffer); i++){
        //buffer[i] = i + 1;
    //}
    //cout<<setw(2)<<ReverseList(buffer)<<endl;
    //std::cout << "Hello world" << std::endl;
    return 0;
}

