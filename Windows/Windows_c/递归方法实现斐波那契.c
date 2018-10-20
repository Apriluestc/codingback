#define _CRT_SECURE_NO_WARNINGS 1
#define M 10
#include<stdio.h>

int count = 0;
int fib(int n)
{
	if(n == 3)
	{
		count ++;
	}
	if(n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
int main()
{
	int n = M;
    int z = 0;
	fib(n);
	printf("%d\n",fib(n));
	printf("%d\n",count);
	return 0;
}