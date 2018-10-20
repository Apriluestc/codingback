#include<stdio.h>
int main()
{
	int arr[] = {10,18,20£¬1,3,5,6,8,3,7};
	int i = 0;
	int j = 0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}