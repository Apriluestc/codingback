#include <iostream>
#include <iomanip>
#include <list>
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};


/*       pToDeleted
 *           ||
 *           ||
    +-----+-----+-----+-----+-----+-----+----+
    |  1  |  2  |  3  |  4  |  5  |  6  |NULL|
    +-----+-----+-----+-----+-----+-----+----+
                   ||
                   ||
                 pNext

                 ListNode *pNext = pToDeleted->m_pNext; --->>   pNext = &3;
                 pToDeleted->m_nValue = pNext->m_nValue;--->>   2 = 3;
                 pToDeleted->m_pNext = pNext->m_pNext;  --->>   &3 = &4;
    +-----+-----+-----+-----+-----+----+
    |  1  |  3  |  4  |  5  |  6  |NULL|
    +-----+-----+-----+-----+-----+----+
 */
void DeleteNode(ListNode **pHead, ListNode *pToDeleted)
{
    if(pHead == NULL || pToDeleted == NULL)
    {
        return;
    }
    //要删除的节点不是尾节点
    if(pToDeleted->m_pNext != NULL)
    {
        ListNode *pNext = pToDeleted->m_pNext;
        pToDeleted->m_nValue = pNext->m_nValue;
        pToDeleted->m_pNext = pNext->m_pNext;
        delete pNext;
        pNext = NULL;
    }
    //链表只有一个节点,删除头节点
    else if(*pHead == pToDeleted)
    {
        /*
         *
         *       pHead
         *         ||
         *         ||
                +-----+----+
                |  1  |NULL|
                +-----+----+
                   ||
                   ||
               pToDeleted
                                delete pToDeleted;
                                pToDeleted = NULL;
                                pHead = NULL;


         * */
        delete pToDeleted;
        pToDeleted = NULL;
        pHead = NULL;
    }
    //链表有多个节点,删除尾节点
    else
    {

        ListNode *pNode = *pHead;
        while(pNode->m_pNext != pToDeleted)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;  //pNode = pToDeleted;
        delete pToDeleted;
        pToDeleted = NULL;


    }
}

int main()
{
    /*
    int array[] = {1, 2, 3, 4, 5, 6};
    list<int> t1(array, sizeof(array)/sizeof(array[0]));
    DeleteNode(array, &3);
    for(int i = 0; i < length(array); i++)
    {
        std::cout << array[i] << setw(2);
    }
    std::cout << std::endl;
    */
    std::cout << "hello world!" << std::endl;
    return 0;
}

