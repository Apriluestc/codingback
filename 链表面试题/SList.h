/*************************************************************************
	> File Name: SList.h
	> Author: 
	> Mail: 
	> Created Time: Tue Oct 23 20:19:58 2018
 ************************************************************************/

#pragma once

#include <iostream>

using namespace std;

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

//节点结构体
typedef struct ListNode
{
    DataType m_Value;
    struct ListNode* m_pNext;
}ListNode;
//查找，找到了返回地址，没有找到返回NULL

ListNode* SListFind(ListNode* p, DataType data)//不改变链表的值，为 ListNode*
{
    ListNode* cur = p;
    for(cur = p; cur != NULL; cur = cur->m_pNext)
    {
        if(cur->m_Value == data)
        {
            return cur;//返回地址
        }
    }
}
/*
void SListInsert(ListNode* *p,ListNode* pos, DataType m_Value)
{
    if(*p == pos)
    {
        SListPushFront(p, m_Value);
        return;
    }
    ListNode* newNode = CreatNode(m_Value);
    ListNode* cur = *p;
    while(cur->m_pNext != pos)
    {
        cur->m_pNext = newNode;
        newNode->m_pNext = pos;
        cur = cur->m_pNext;
    }


}
*/
void SListInit(ListNode* *p)
{
    assert(p != NULL);
    *p = NULL;

}
void SListDestroy(ListNode* *p)
{
    assert(p != NULL);

}
static ListNode* CreatNode(DataType m_Value)
{
    ListNode* pNode = (ListNode *)malloc(sizeof(ListNode));
    pNode->m_Value = m_Value;
    pNode->m_pNext = NULL;
    return pNode;
}
//尾删
void SListPopBack(ListNode* *p)
{
    assert(p != NULL);
    assert(*p != NULL);//判断链表是否为空
    if((*p)->m_pNext == NULL)
    {
        free(p);
        p = NULL;
        return ;
    }
    //链表中至少有两个
    ListNode* cur = *p;
    while(cur->m_pNext != NULL)
    {
        //free(cur->m_pNext);
        cur = cur->m_pNext;
    }
    free(cur->m_pNext);
    cur->m_pNext = NULL;
}
//头删

//尾插
void SListPushBack(ListNode* *p, DataType m_Value)
{
    ListNode* pNode = CreatNode(m_Value);/* 申请节点，赋值且插入 */
    assert(p != NULL);//传入地址不为空
    if(*p == NULL)/* 链表为空 */
    {
        *p = pNode;
        return ;
    }
    //找链表中的最后一个节点
    //ListNode* pNode = CreatNode(m_Value);//申请节点，赋值且插入
    ListNode* cur = *p;
    while(cur->m_pNext != NULL)
    {
        cur = cur->m_pNext;
    }
    cur->m_pNext = pNode;
}
//头插
void SListPushFront(ListNode* *p, DataType m_Value)
{
    assert(p != NULL);
    //assert(*p != NULL);
    ListNode* pNode = (ListNode *)malloc(sizeof(ListNode));
    pNode->m_Value = m_Value;
    pNode->m_pNext = NULL;
    //pNode->m_pNext = *p;
    *p = pNode;
}

void SListPrint(ListNode* p)
{
    ListNode* cur = p;
    while(cur != NULL)
    {
        printf("%d ", cur->m_Value);
        cur = cur->m_pNext;
    }
    printf("\n");
}

void SListTest()
{
    ListNode* pFirst;

    SListInit(&pFirst);//初始化
    //链表头插
    //SListPushFront(&pFirst, 0);
    SListPushFront(&pFirst, 1);
    SListPushFront(&pFirst, 2);
    SListPushFront(&pFirst, 3);
    SListPushFront(&pFirst, 4);
    SListPushFront(&pFirst, 5);
    SListPrint(pFirst);
    //链表尾插
    SListPushBack(&pFirst, 4);
    SListPushBack(&pFirst, 3);
    SListPushBack(&pFirst, 2);
    SListPushBack(&pFirst, 1);
    SListPrint(pFirst);//打印尾插之后的链表
    SListPopBack(&pFirst);
    SListPopBack(&pFirst);
    SListPopBack(&pFirst);
    SListPrint(pFirst);
    //SListInsert();
    //CreatNode(m_Value);


}
ListNode* SList(ListNode* pHead1)
{
    //if(pHead == pHead1)
    //{
    SListInit(&pHead1);
    SListPushBack(&pHead1, 0);
    SListPushBack(&pHead1, 1);
    SListPushBack(&pHead1, 2);
    SListPushBack(&pHead1, 3);
    SListPushBack(&pHead1, 4);
    SListPushBack(&pHead1, 5);
    SListPushBack(&pHead1, 6);
    SListPushBack(&pHead1, 7);
    SListPushBack(&pHead1, 8);
    SListPushBack(&pHead1, 9);
    //return pHead1;
    //}
    /*
    else
    {
        ListNode* pHead2;
        SListInit(&pHead2);
        SListPushFront(&pHead2, 0);
        SListPushFront(&pHead2, 1);
        SListPushFront(&pHead2, 2);
        SListPushFront(&pHead2, 3);
        SListPushFront(&pHead2, 4);
        SListPushFront(&pHead2, 5);
        SListPushFront(&pHead2, 6);
        SListPushFront(&pHead2, 7);
        SListPushFront(&pHead2, 8);
        SListPushFront(&pHead2, 9);
    }*/
    return pHead1;
}


