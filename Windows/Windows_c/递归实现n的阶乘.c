#include<stdio.h>
int Jc(int n)
{
	if(n<=1)
	{
		return 1;
	}
	else
	{
		return n*Jc(n-1);
	}
}
int main()
{
	int n = 5;
    Jc(n);
	printf("%d\n",Jc(n));
	return 0;
}