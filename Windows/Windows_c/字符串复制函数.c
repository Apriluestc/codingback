#include<stdio.h>
char *my_strcpy(char *dest, const char *src)
{
	char *tmp = dest;
	while(*dest++ = *src++)
	{
		;
	}
	return tmp;
}
int main()
{
	char arr1[] = "abcdefgh";
	char arr2[20] = {0};
	printf("%s\n",my_strcpy(arr2, arr1));
	return 0;
}