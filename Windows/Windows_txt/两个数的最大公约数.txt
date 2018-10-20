#include<stdio.h>
int main()
{
	int arr1[] = {0,1,2,3,4};
	int arr2[] = {5,6,7,8,9};
	int size = sizeof(arr1)/sizeof(arr1[0]);
	int i = 0;
	for(i=0;i<size;i++)
	{
		arr1[i] ^= arr2[i];
		arr2[i] ^= arr1[i];
		arr1[i] ^= arr2[i];
		printf("%d ",arr1[i]);
	}
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");
	return 0;
}