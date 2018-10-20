#include<stdio.h>
int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	for(i=0;i<size;i++)
	{
		int j = 0;
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				/*int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;*/
				arr[j] ^= arr[j+1];
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
			}
		}
	}
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}