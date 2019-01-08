#pragma once
//#ifdef __SEQ_LIST_H__
//#define _SEQ_LIST_H__

//#endif
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX_SIZE (100)
typedef int DataType;
typedef struct SeqList
{
    int array[MAX_SIZE];  //空间大小
    int size;   //其中已有数据个数
                //下一个可用空间的标
}SList;

/*
bool SeqListEmpty(const SList* pSeq)
{
    return pSeq->size == 0;
}
bool SeqListFull(const SList* pSeq)
{
    return pSeq->size = MAX_SIZE;
}
*/


//初始化、销毁
void SeqListInit(SList* pSeq)
{
    assert(pSeq != NULL);//传地址不为空：断言 assert
    pSeq->size = 0;
    
}
void SeqListDestroy(SList* pSeq)
{
    assert(pSeq != NULL);
    pSeq->size = 0;
}
//相同的元素都删除
void SeqListRemoveAll(SList* pSeq, DataType data)
{
    //新建数组，把不等于 data 的数据 copy 到 extra
    DataType* extra = (DataType *)malloc(sizeof(DataType) * pSeq->size);//空间复杂度高
    int i = 0, j = 0;
    for(; i < pSeq->size; i++)
    {
        if(pSeq->array[i] != data)
        {
            extra[j++] = pSeq->array[i];
        }
    }
    //从 extra copy 回来
    int k = 0;
    for(k = 0; k < j; k++)
    {
        pSeq->array[k] = extra[k];
    }
    free(extra);
}


//根据数据做删除
/*

int SeqListRemove(SList* pSeq, DataType data)
{
    int pos = SeqListFind(pSeq, data);
    if(pos == -1)
    {
        return -1;
    }
    SeqListErase(pSeq, pos);
}
*/

//查找   key
int SeqListFind(const SList* pSeq, DataType data)
{
    int i = 0;
    for(i = 0; i < pSeq->size; i++)
    {
        if(data == pSeq->array[i])
        {
            return i;
        }
    }
    return -1;
}




//增、删、改、查


//头插



void SeqListInsert(SList* pSeq, int pos, DataType data)
{
    assert(pSeq->size < MAX_SIZE);
    assert(pos >= 0 && pos <=pSeq->size);
    int i = 0;
    for(i = pSeq->size; i > pos + 1; i--) // 2 0 2 1     2 0 5 2 1
    {
        pSeq->array[i]  = pSeq->array[i-1];//往后移动
    }
    pSeq->array[pos] = data;
    pSeq->size += 1;
}


void SeqListPopBack(SList* pSeq)
{
    assert(pSeq != NULL);//传入地址不为空指针
    assert(pSeq->size > 0);//顺序表不为空(size)空间

    pSeq->size--;
}
void SeqListPopFront(SList* pSeq)
{
    assert(pSeq != NULL);
    assert(pSeq->size > 0);
#if 1
    int i = 0;
    for(i = 0; i <= pSeq->size-2; i++)
    {
        pSeq->array[i] = pSeq->array[i+1];
    }
#else
    int j = 0
    for(j = 1; j < size; j++)
    {
        pSeq->array[i] = pSeq->array[i+1];
    }
#endif
    pSeq->size--;

}

void SeqListErase(SList* pSeq, int pos)
{
    assert(pSeq != NULL);
    assert(pSeq->size > 0);
    int i = 0;

    //  i   空间 [pos, size - 2]
    for(i = pos; i <= pSeq->size - 2; i++)
    {
        pSeq->array[i] = pSeq->array[i+1];
    }
    pSeq->size--;
}


void SeqListPushFront(SList* pSeq, DataType data)
{
    assert(pSeq->size < MAX_SIZE);

    //移数据
#if 1
    int i = 0;
    for(i = pSeq->size -1; i >= 0; i--)
    {
        pSeq->array[i+1] = pSeq->array[i];
    }
#else
    int j = 0;
    for(j = pSeq->size - 1; j > 0; j--)
    {
        pSeq->array[j] = pSeq->array[j-1];
    }
#endif
    pSeq->array[0] = data;
    pSeq->size += 1;

}



//尾插
void SeqListPushBack(SList* pSeq, DataType data)
{
    if(MAX_SIZE == pSeq->size)
    {
        printf("满了\n");
            return;
    }

    pSeq->array[pSeq->size] = data;
    pSeq->size += 1;
}
void SeqListPrint(const SList* pSeq)
{
    int i = 0;
    for(i = 0; i < pSeq->size; i++)
    {
        printf("%d ", pSeq->array[i]);
    }
    printf("\n");
}
void SeqListTest()
{
    SList seqlist;
    SeqListInit(&seqlist);
    assert(seqlist.size == 0);

    SeqListPushBack(&seqlist, 1);
    SeqListPushBack(&seqlist, 2);
    SeqListPrint(&seqlist);//传地址，减少形参大小

    SeqListPushFront(&seqlist, 0);
    SeqListPushFront(&seqlist, 2);
    SeqListPrint(&seqlist);
    SeqListInsert(&seqlist, 3, 5);
    SeqListPrint(&seqlist);
    SeqListPopFront(&seqlist);
    SeqListPrint(&seqlist);
    SeqListErase(&seqlist, 3);
    SeqListPrint(&seqlist);
    //SeqListRemove(&seqlist, 1);
    //SeqListPrint(&seqlist);
    
    SeqListRemoveAll(&seqlist, 1);
    SeqListPrint(&seqlist);
}



void Bubblesort(SList* pSeq)
{
    assert(pSeq != NULL);
    assert(pSeq->size > 0);
    int i = 0;
    for(i = 0; i < pSeq->size - 1; i++)
    {
        int j = 0;
        int flag = 1;
        for(j = 0; j < pSeq->size- i- 1; j++)
        {
            flag = 1;
            if(pSeq->array[i] < pSeq->array[i+1])
            {
                int tmp = pSeq->array[i];
                pSeq->array[i] = pSeq->array[i+1];
                pSeq->array[i+1] = tmp;
                flag = -1;
            }
        }
        //无交换，已经有序 
        if(flag)
        {
            break;
        }
    }
}
void Swap(int* pa, int* pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
//typedef int size_t;
void SelectSort(SList* pSeq)
{
    assert(pSeq != NULL);
    //区间还剩一个数字
    size_t minspace = 0;
    size_t maxspace = pSeq->size;
    size_t minpos = minspace;
    size_t maxpos = maxspace;
    while(minspace < maxspace)
    {
        int j = 0;
        for(j = minspace; j <+ maxspace; j++)
        {
            if(pSeq->array[j] < pSeq->array[minpos])
            {
                minpos = j;
            }
            if(pSeq->array[j] > pSeq->array[maxpos])
            {
                maxpos = j;
            }
        }
        Swap(pSeq->array + minspace, pSeq->array + minpos);
        Swap(pSeq->array + maxspace, pSeq->array + maxpos);
        minspace++, maxspace--;

    }
}

void SortTest()
{
    SList* seqlist;
    SeqListTest();
    Bubblesort(seqlist);
    SelectSort(seqlist);
}
