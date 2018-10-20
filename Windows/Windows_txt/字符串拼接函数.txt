#include<stdio.h>
char *my_strcat(char *dest, char *src)
{char *temp = dest;
    while(*dest)
	{
		dest++;
	}
	while(*dest++ = *src++)
	{
		;
	}
	return temp;
}
int main()
{
	char arr1[20] = "abcde";
	char arr2[20] = "12345";
	printf("%s\n" ,my_strcat(arr1, arr2));
	return 0;
}