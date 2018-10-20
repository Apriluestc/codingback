#define ROW 7
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for(i=1;i<=ROW;i++)
	{
		for(j=1;j<=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=ROW-1;i>=0;i--)
	{
		for(j=1;j<=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}