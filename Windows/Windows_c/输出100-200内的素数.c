#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for(i = 100; i<=200; i++)
	{
		for(j = 2; j<=i-1; j++)
		{
			if(i%j == 0)
			{
				break;
			}
			if(i-1 == j)
			{
				printf("%d ",i);
			}
		}
	}
	printf("\n");
	return 0;
}