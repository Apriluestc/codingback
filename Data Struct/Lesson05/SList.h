/*************************************************************************
	> File Name: SList.h
	> Author: 
	> Mail: 
	> Created Time: Tue Oct 23 20:19:58 2018
 ************************************************************************/

#ifndef _SLIST_H
#define _SLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

//节点结构体
typedef struct Node
{
    DataType data;
    struct Node* next;
}Node;
//查找，找到了返回地址，没有找到返回NULL

Node* SListFind(Node* p, DataType data)//不改变链表的值，为 Node*
{
    Node* cur = p;
    for(cur = p; cur != NULL; cur = cur->next)
    {
        if(cur->data == data)
        {
            return cur;//返回地址
        }
    }
}
/*
void SListInsert(Node* *p,Node* pos, DataType data)
{
    if(*p == pos)
    {
        SListPushFront(p, data);
        return;
    }
    Node* newNode = CreatNode(data);
    Node* cur = *p;
    while(cur->next != pos)
    {
        cur->next = newNode;
        newNode->next = pos;
        cur = cur->next;
    }


}
*/
void SListInit(Node* *p)
{
    assert(p != NULL);
    *p = NULL;

}
void SListDestroy(Node* *p)
{
    assert(p != NULL);

}
static Node* CreatNode(DataType data)
{
    Node* pNode = (Node *)malloc(sizeof(Node));
    pNode->data = data;
    pNode->next = NULL;
    return pNode;
}
//尾删
void SListPopBack(Node* *p)
{
    assert(p != NULL);
    assert(*p != NULL);//判断链表是否为空
    if((*p)->next == NULL)
    {
        free(p);
        p = NULL;
        return ;
    }
    //链表中至少有两个
    Node* cur = *p;
    while(cur->next != NULL)
    {
        //free(cur->next);
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}
//头删

//尾插
void SListPushBack(Node* *p, DataType data)
{
    Node* pNode = CreatNode(data);/* 申请节点，赋值且插入 */
    assert(p != NULL);//传入地址不为空
    if(*p == NULL)/* 链表为空 */
    {
        *p = pNode;
        return ;
    }
    //找链表中的最后一个节点
    //Node* pNode = CreatNode(data);//申请节点，赋值且插入
    Node* cur = *p;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = pNode;
}
//头插
void SListPushFront(Node* *p, DataType data)
{
    assert(p != NULL);
    //assert(*p != NULL);
    Node* pNode = (Node *)malloc(sizeof(Node));
    pNode->data = data;
    pNode->next = NULL;
    //pNode->next = *p;
    *p = pNode;
}

void SListPrint(Node* p)
{
    Node* cur = p;
    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void SListTest()
{
    Node* pFirst;

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
    //CreatNode(data);


}


#endif
