#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
//静态栈
template<class T>
class Stack()
{
public:
    Stack()
        :_a(NULL)
        ,_size(0)
        ,_capacity(0)
    {}
    void Push(const T& x)
    {
        CheckCapacity();
        _a[_size++] = x;
    }
    void Pop()
    {
        assert(_size > 0);
        --_size;
    }
    T& Top()
    {
        assert(_size >  0);
        return _a[_size-1];
    }
    void CheckCapacity()
    {
        if(_size >= capacity)
        {
            T* tmp = new T[_capacity*2 + 3];
            if(_a)
            {
                size_t i = 0;
                for(i = 0; i<_size;++i)
                {
                    tmp[i] = _a[i];
                }
                delete[] _a;
                _a = tmp;
            }
        }
    }
    ~Stack() {}

protected:
    T* _a;
    size_t _size;
    size_t _capacity;

};

