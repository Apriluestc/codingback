#include <iostream>
#include <stack>
using namespace std;

/*
 *用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型
 * */


class Queue
{
public:
    void Push(int val)
    {
        stack1.push(val);
    }
    int Pop()
    {
        int tmp = 0;
        if(stack2.empty())  //栈 2 为空
        {
            while(!stack1.empty())  //栈 1 不空，继续出栈，接着入栈 2 再出栈
            {
                tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
        }
        tmp = stack2.top();
        stack2.pop();
        return tmp;
    }
private:
    stack<int> stack1;  //入队列
    stack<int> stack2;  //出队列
};


int main()
{
    Queue q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);
    return 0;
}

