#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Cf(int n,int k)
{
	
	if(k>0)
	{
		return n*Cf(n,k-1);
    }
	return 1;
}
int main()
{
	int n = 2;
	int k = 3;
    Cf(n,k);
	printf("%d\n",Cf(n,k));
	return 0;
}