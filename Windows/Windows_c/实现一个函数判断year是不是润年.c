#include<stdio.h>
int main()
{
	int year = 0;
	for(year=1000;year<=2000;year++)
	{
		if((year%400 == 0) || ((year%4 == 0) && (year%100 != 0)))
		{
			printf("%d ",year);
		}
	}
	return 0;
}