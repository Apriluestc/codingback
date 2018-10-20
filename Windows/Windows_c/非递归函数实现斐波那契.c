#define _CRT_SECURE_NO_WARNINGS 1
#define M 10
#include<stdio.h>
int fib(int n)
{
	int result;
	int pre_result;
	int next_older_result;
	result = pre_result = 1;
	while(n > 2)
	{
		n -= 1;
		next_older_result = pre_result;
		pre_result = result;
		result = pre_result + next_older_result;
	}
	return result;
}
int main()
{
	int n = M;
	fib(n);
	printf("%d\n",fib(n));
	return 0;
}