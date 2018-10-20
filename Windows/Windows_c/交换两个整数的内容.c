#include<stdio.h>
void change(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("%d %d\n",a,b);
	change(a,b);
    printf("%d %d\n",a,b);
	return 0;
}
//
//
//
//
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
//
//
//
//
#include<stdio.h>
void Swap(int *pa,int *pb)
{
	int tmp = *pa;
	    *pa = *pb;
	    tmp = *pa;
}
int main()
{
    int a = 10;
	int b = 20;
	printf("%d %d\n",a,b);
	Swap(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}
