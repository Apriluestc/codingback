#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
template<class T>
struct QueueNode
{
    T _data;
    QueueNode<T>* _next;
};
template<class T>
class Queue
{
    typedef QueueNode<T>* Node;
public:
    Queue()
        :_head(NULL)
        ,_tail(NULL)
    {}

    void Push(const T& x)
    {
        if(-head == NULL)
        {
            return ;
        }
        else if(_head == _tail)
        {
            _head = _tail = NULL;
        }
        else
        {
            Node* next = _head->_naxt;
            delete _head;
            _head = next;
        }
    }
    bool Empty()
    {
        return _head == NULL;
    }
    size_t Size()
    {
        size_t size = 0;
        Node* cur = _head;
        while(cur)
        {
            ++size;
            cur = cur->_next;
        }
        return size;
    }
    ~Queue() {}

protected:
    Node* _head;
    Node* _tail;


};

//void TestQueue()
//{
    //Queue<int> q;
    //q.Push(1);
    //q.Push(2);
    //q.Push(3);
    //q.Push(4);
    //while(!q.Empty())
    //{
        //cout<<q.Front()<<" ";
        //q.Pop();
    //}
    //cout<<endl;
//}
