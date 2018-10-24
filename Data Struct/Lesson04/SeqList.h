/*************************************************************************
	> File Name: SeqList.h
	> Author: 
	> Mail: 
	> Created Time: Tue Oct 23 19:16:35 2018
 ************************************************************************/

#ifndef _SEQLIST_H
#define _SEQLIST_H
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct SeqList
{
    DataType* array;
    int size;//尺寸，里面有多少东西
    int capacity;//容量  对应MAX_SIZE
}SList;



//初始化动态顺序表
void SeqListInit(SList* pSeq)
{
    const int init_capacity = 5;//容量固定
    assert(pSeq != NULL);
    pSeq->size = 0;//size 置零
    pSeq->capacity = init_capacity;
    pSeq->array = (DataType *)malloc(sizeof(DataType)* init_capacity);
    assert(pSeq->array);
}


//销毁动态顺序表
void SeqListDestroy(SList* pSeq)
{
    free(pSeq->array);
    pSeq->array = NULL;
    pSeq->size = 0;
    pSeq->capacity = 0;
}



//判断是否要进行扩容
void ExpandIfRequired(SList* pSeq)
{
    //表未满，不需要扩容
    if(pSeq->size < pSeq->capacity)
    {
        return ;
    }
    //表已经满了，需要扩容
    int newCapacity = pSeq->capacity * 2;//一般情况，一个不够给两个，再不够给定三个 capacity
    DataType* newArray = (DataType *)malloc(sizeof(DataType) * newCapacity);
    assert(newArray);
    int i = 0;
    for(i = 0; i < pSeq->size; i++)
    {
        newArray[i] = pSeq->array[i];//搬移数组，将老数组元素搬移到新数组中
    }

    free(pSeq->array);//释放老数组空间
    pSeq->array = newArray;//更新新数组
    pSeq->capacity = newCapacity;//更新 capacity
}


//动态顺序表尾插
void SeqListPushBack(SList* pSeq, DataType data)
{
    assert(pSeq != NULL);
    //扩容
    ExpandIfRequired(pSeq);//调用判断是否进行扩容函数
    pSeq->array[pSeq->size++] = data;
}


//动态顺序表打印
void SeqListPrint(const SList* pSeq)
{
    int i = 0;
    for(i = 0; i <pSeq->size; i++)
    {
        printf("%d ", pSeq->array[i]);
    }
    printf("\n");
}

void SeqListTest()
{
    SList pSeq;
    SeqListInit(&pSeq);//初始化动态顺序表
    /* 尾插调试 */
    SeqListPushBack(&pSeq, 1);
    SeqListPushBack(&pSeq, 2);
    SeqListPushBack(&pSeq, 3);
    SeqListPushBack(&pSeq, 4);
    SeqListPushBack(&pSeq, 5);
    /* 打印尾插之后的顺序表 */
    SeqListPrint(&pSeq);

}


#endif
