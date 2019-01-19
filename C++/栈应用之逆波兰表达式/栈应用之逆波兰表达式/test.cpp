#include <iostream>

using namespace std;

#include <stack>
#include <assert.h>

enum Type
{
	OP_NUM,	//操作数
	OP_SYMBOL,	//操作符
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

int CountRPN(Cell *rpn, size_t n)
{
	stack<int> s;
	for (size_t i = 0; i < n; i++)
	{
		if (rpn[i]._type == OP_NUM)//是操作数  入栈
		{
			s.push(rpn[i]._value);
		}
		else//遇到了操作符
		{
			int right = s.top(); //右操作数在左操作数之后入栈
			s.pop();
			int left = s.top();//左操作数
			s.pop();
			switch (rpn[i]._value)//看它是哪个操作符，就执行哪个，把结果再放入栈中
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
			}
		}
	}
	assert(s.size() == 1);//最后结束时，栈里应该只有一个数据，为最终结果
	return s.top();//返回栈顶数据（最终结果）
}
//12*(3+4)-6+8/2+2
int main()
{
	Cell RPN[] =
	{
		{ OP_NUM, 12 },
		{ OP_NUM, 3 },
		{ OP_NUM, 4 },
		{ OP_SYMBOL, ADD },
		{ OP_SYMBOL, MUL },
		{ OP_NUM, 6 },
		{ OP_SYMBOL, SUB },
		{ OP_NUM, 8 },
		{ OP_NUM, 2 },
		{ OP_SYMBOL, DIV },
		{ OP_SYMBOL, ADD },
		{ OP_NUM, 2 },
		{ OP_SYMBOL, ADD },

	};
	cout << sizeof(RPN) << " " << sizeof(Cell) << endl;
	cout << "结果：" << CountRPN(RPN, sizeof(RPN) / sizeof(Cell)) << endl;
	return 0;
}