#include<stdio.h>
int main()
{
	int i = 0;
    for(i = 1000; i<=2000; i++)
	{
		if((i%400 == 0)||((i%4 == 0)&&(i%100 != 0)))
		{
			printf("%d ",i);
		}
	}
	return 0;
} 