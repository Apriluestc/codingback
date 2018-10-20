#include<stdio.h>
void Isprime()
{
	int i = 0;
	for(i=100;i<=200;i++)
	{
		int j = 0;
		for(j=2;j<i;j++)
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
}
int main()
{
	Isprime();
	return 0;
}