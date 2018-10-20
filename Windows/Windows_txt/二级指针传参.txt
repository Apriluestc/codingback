#include<stdio.h>
void test(int **ptr)
{
	printf("num = %d\n",**ptr);
}
int main()
{
	int n = 10;
	int *p = &n;
	int **pp = &p;
	test(pp);
	test(&p);
	return 0;
}