#include<stdio.h>
void *memcpy(void *dest, const void *src, int count)
{
	void * ret = dest;
	while(count--)
	{
		*(char *)dest = *(char *)src;
		dest = (char *)dest + 1;
		src = (char *)src+ 1;
	}
	return (ret);
}
int main()
{
	char arr1[20] = {0};
	//char arr1[20] = "abcdefg";
	char arr2[20] = "1234";
	int size = sizeof(arr2)/sizeof(arr2[0]);
	printf("%s\n",memcpy(arr1, arr2, size));
	return 0;

}