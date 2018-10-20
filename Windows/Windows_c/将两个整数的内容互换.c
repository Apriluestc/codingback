#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int tmp = 0;
	printf("%d %d\n",a,b);
	tmp = a;
	a = b;
	b = tmp;
	printf("%d %d\n",a,b);
	return 0;
}

#include<stdio.h>
void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
	printf("%d %d\n",*pa,*pb);
}
int main()
{
	int a = 10;
	int b = 20;
	printf("%d %d\n", a,b);
	swap(&a, &b);
	return 0;
}
不创建临时变量，将两个整数的内容互换
#include<stdio.h>
void swap(int *pa, int *pb)
{
	*pa ^= *pb;
	*pb ^= *pa;
	*pa ^= *pb;
	printf("%d %d\n", *pa, *pb);
}
int main()
{
	int a = 10;
	int b = 20;
	printf("%d %d\n",a, b);
	swap(&a, &b);
	return 0;
}