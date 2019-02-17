#include <iostream>
using namespace std;
#include <stack>

/*
 *定义栈的数据结构，
 请在该类型中实现一个能够得到栈中所含最小元素的min函数
 （时间复杂度应为O（1））
 * */

class MinStack
{
public:
    void Push(int val)
    {
        if(val < _minstack.top())
            _minstack.push(val);
    }

    void Pop()
    {}

    int Top()
    {
        return _stack.top();
    }

    int min()
    {
        return _minstack.top();
    }

private:
    stack<int> _stack;
    stack<int> _minstack;
}


int main()
{
    //std::cout << "Hello world" << std::endl;
    return 0;
}

