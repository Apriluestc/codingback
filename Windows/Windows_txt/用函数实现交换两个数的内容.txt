#include<stdio.h>
void swap(int *pa, int *pb)
{
	int tmp = *pa;
	printf("%d %d",*pa, *pb);
	printf("\n");
	*pa = *pb;
	*pb = tmp;
	printf("%d %d",*pa, *pb);
}
int main()
{
	int a = 10;
	int b = 20;
	swap(&a, &b);
	return 0;
}