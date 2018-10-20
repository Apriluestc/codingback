#include<stdio.h>
void print(int n)
{
	int z = 0;
	if(n>9)
	{
		print(n/10);
	}
	printf("%d ",n%10);
}
int main()
{
	int ret = 0;
	int num = 1234;
    print(num,ret);
	return 0;
}