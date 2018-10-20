#include<stdio.h>
int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int mul(int x, int y)
{
    return x * y;
}
int div(int x, int y)
{
    return x/y;
}
int main()
{
    int a, b;
    int input = 1;
    int ret = 0;
    printf("***********************************\n");
    printf("****** 1.my_add     2.my_sub ******\n");
    printf("****** 3.my_mul     4.my_div ******\n");
    printf("*************  0.exit *************\n");
    while(input)
    {
	printf("请选择:");
	scanf("%d %d",&a, &b);
	switch(input)
	{
	case 1:
		printf("输入操作数:");
		scanf("%d %d",&a, &b);
		ret = add(a, b);
		break;
	case 2:
		printf("输入操作数");
		scanf("%d %d",&a, &b);
		ret = sub(a, b);
		break;
	case 3:
		printf("输入操作数");
		scanf("%d %d",&a, &b);
		ret = mul(a, b);
		break;
	case 4:
		printf("输入操作数");
		scanf("%d %d",&a, &b);
		ret = div(a, b);
		break;
	}
    }
    printf("ret = %d\n",ret);
    return 0;
}
