#include<stdio.h>
int main()
{
	int deno = 0;
	int sum = 1;
	int i = 1;
	for(deno=2;deno<=100;deno++)
	{
		i *= -1;
		sum = sum + i/deno;
	}
	printf("%d\n",sum);
	return 0;
}