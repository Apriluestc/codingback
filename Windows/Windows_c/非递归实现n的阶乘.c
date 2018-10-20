#include<stdio.h>
int Jc(int n)
{
	int result = 1;
	while(n>1)
	{
		result = result * n;
		n = n - 1;
	}
	return result;
}
int main()
{
	int n = 5;
	Jc(n);
	printf("%d\n",Jc(n));
	return 0;
}