#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>  
#include <assert.h>  
#include <stack>  
using namespace std;

class
{
public:
	bool Check(int *stack_in, int *stack_out, int len_in, int len_out)
	{
		assert(stack_in && stack_out);
		if (len_in != len_out)         //两个序列长度不相等，不合法  
			return false;
		stack<int> s;
		int j = 0;
		int i = 0;
		for (; i < len_in; i++)
		{
			s.push(stack_in[i]);
			while (s.size() > 0 && s.top() == stack_out[j])//入栈序列栈顶元素与当前出栈序列元素不相等，不合法  
			{
				s.pop();
				j++;
			}
		}
		return (s.size()>0) ? false : true;                //当所有出栈序列元素都匹配完之后，栈不为空，不合法  
	}

};
int main()
{
	return 0;
}