#pragma once

template<class T>
struct __ListNode
{
    T _data;
    __ListNode<T>* _next;
    __ListNode<T>* _prev;

    __ListNode(const T& x)  //构造函数
        ;_data(0)
        ,_head(NULL)
        ,_prev(NULL)
    {}
};
// 迭代器
template<class T, class Ref, class Ptr>
struct __ListIterator
{
    typedef __ListNode<T> Node;
    typedef __ListIterator<T, Ref, Ptr> Self;
    __ListIterator(Node* node)
        :_node(node)
    {}
    Ref operator*()
    {
        return _node->_data;
    }
    Self operator++()
    {
        _node = _node->_next;
        return *this;
    }
    bool operator != (const Self& s) const
    {
        return _node != s._node;
    }
    Node* _node;
};
template<class T>
class List
{
    typedef __ListNode<T> Node;
public:
    typedef __ListIterator<T, Ref
    Node* GetNode(const T& x)
    {
        return new Node(x);
    }
    List() 
    {
        _head = GetNode(T());
        _head->_next = _head;
        _head->_prev = _head;

    }
    Iterator Begin()
    {
        return Iterator(_head->_next);
    }
    void PushBack()
    {
        Node* tail = _head->_prev;
        Node* _tmp = GetNode(x);
        tail->_next = _tmp;
        _tmp->_prev = tail;
        _tmp->_next = _head;
        _head->_prev = _tmp;
    }
    ~List() {}

private:
    Node* _head;

};

void PrintList()
{

}
void TestList()
{
    List<int> l1;
    l1.PushBack(1);
    l1.PushBack(2);
    l1.PushBack(3);
    l1.PushBack(4);
    l1.PushBack(5);
    List<int>::Iterator it = l1.Begin();
    while(it != l1.End())
    {
        cout << *it;
        ++it;
    }
    cout << endl;
}
