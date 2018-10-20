#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int c = 18;
	int tmp = 0;
	if(a<b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if(a<c)
	{
		tmp = a;
		a = c;
		c = tmp;
	}
	if(b<c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n",a,b,c);
	return 0;
}