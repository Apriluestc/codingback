#define M 3
#include<stdio.h>
int main()
{
	int sum = 0;
	sum = M + M*11 + M*111 +M*1111 + M*11111;
	printf("%d\n",sum);
	return 0;
}