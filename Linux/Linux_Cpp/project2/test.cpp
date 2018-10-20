#include "Maze.h"
#include<vector>

enum Type
{
    OP_NUM,
    OP_SYMBOL,
    ADD,
    SUB,
    MUL,
    DIV,
};

struct Cell
{
    Type _type;
    int _value;
};

class Count
{
protected:
    vector<Cell> in;
    vector<Cell> post;
};
// RPN结构体数组
Cell RPN[] = {
    {OP_NUM, 12},
    {OP_NUM, 3},
    {OP_NUM, 4},
    {OP_SYMBOL, ADD},
    {OP_SYMBOL, MUL},
    {OP_NUM, 6},
    {OP_SYMBOL, SUB},
    {OP_NUM, 8},
    {OP_NUM, 2},
    {OP_SYMBOL, DIV},
    {OP_SYMBOL, ADD},
};

int CountRPN(Cell* rpn, size_t n)
{
    stack<int> s;
    for(size_t i = 0; i < n; ++i)
    {
        if(rpn[i]._type == OP_NUM)
        {
            s.push(rpn[i]._value);
        }
        else
        {
            //int left = ;
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();
            switch(rpn[i]._value)
            {
            case ADD:
                s.push(left + right);
                break;
            case SUB:
                s.push(left - right);
                break;
            case MUL:
                s.push(left * right);
                break;
            case DIV:
                s.push(left / right);
                break;
            default:
                break;
            }
        }
    }
    assert(s.size() == 1);
    return s.top();
}
int main()
{

    cout<<"计算结果："<<CountRPN(RPN, sizeof(RPN)/sizeof(Cell))<<endl;
    //TestMaze();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

