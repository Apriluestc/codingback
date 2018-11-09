#include <iostream>
#include <iomanip>
//#include <vector>
using namespace std;
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void PrintListReverse(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead->m_pNext != NULL)
        {
            PrintListReverse(pHead->m_pNext);
        }
        std::cout << pHead->m_nValue << std::setw(2);
    }
    std::cout << std::endl;
}
int main()
{
    /*
    ListNode *pHead = NULL;
    vector<void> temp = PrintListReverse(pHead);
    for(int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }
    cout << endl;
    */
    std::cout << "Hello world" << std::endl;
    return 0;
}

