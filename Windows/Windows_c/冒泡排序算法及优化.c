#include<stdio.h>
int main()
{
	int arr[] = {10,18,20};
	int i = 0;
	int j = 0;
	int flag = 1;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;i++)
	{
		flag = 0;
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j]<arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flag = 1;
			}
		}
	}
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
int main()
{
	int arr[] = {10,18,20};
	int i = 0;
	int j = 0;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j]<arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}