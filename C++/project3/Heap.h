#pragma once

#include<iostream>
using namespace std;
#include<assert.h>
#include<vector>
template<class T>
class Heap
{
public:
    Heap()
    {}
    Heap(T* a, size_t n)
    {
        _a.reserve(n);
        for(size_t i = 0; i < n; ++i)
        {
            _a.push_back(a[i]);
        }
        //建堆
        for(int i = (_a.size()-2)/2; i >= 0; --i)
        {
            AdjustDown(i);
        }
    }
    void Push(const T& x)
    {
        _a.push_back(x);
        AdjustUp(_a.size()-1);
    }
    void Pop()
    {
        swap(_a[0], _a[_a.size()-1]);
        _a.pop_back();
        AdjustDown(0);
        
    }
    void AdjustUp(int child)
    {
        int parent = (child-1)/2;
        while(parent >= 0)
        {
            if(_a[parent] < _a[child])
            {
                swap(_a[parent], _a[child]);
                child = parent;
                parent = (child-1)/2;
            }
            else
            {
                break;
            }
        }
    }
    //向下调整建立大堆
    void AdjustDown(int root)
    {
        int parent = root;
        int child = parent*2 + 1;
        while(child < _a.size())//左孩子存在继续调整
        {
            if(child+1 < _a.size() && _a[child+1] > _a[child])
            {
                ++child;
            }
            //选出大的那一个孩子
            if(_a[child] > _a[parent])
            {
                swap(_a[child], _a[parent]);
                parent = child;
                child = child*2 + 1;
            }
            else
            {
                break;
            }
        }
    }
    ~Heap() {}

protected:
    vector<T> _a;

};
void TestHeap()
{
    int a[] = {10, 11, 13, 12, 16, 18, 15, 17, 14, 19};
    Heap<int> hp1(a, sizeof(a)/sizeof(a[10]));
}
