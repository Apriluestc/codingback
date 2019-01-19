#include <iostream>
#include <string>
using namespace std;

#if 0


int len(char* str) {//计算字符串的长度
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		length++;
	}
	return length;
}
char* reverseWord(char* str, int i, int j) {//根据i,j的位置反转单词
	char temp;
	while (i < j) {
		temp = str[i]; str[i] = str[j]; str[j] = temp;
		i++; j--;
	}
	return str;
}
char *strReverse(char *str)
{//字符串反转，用到了上面的函数
	int length = len(str);
	char *newStr = reverseWord(str, 0, (length - 1));

	for (int i = 0; i<length; i++) {
		int len = 0;
		while (newStr[i] != ' ' && newStr[i] != '\0') {
			len++;
			i++;
		}
		int k = i - len, j = i - 1;
		reverseWord(newStr, k, j);
	}

	return str;
}

int main(int argc, const char * argv[])
{
	char str[] = "I come from China.";
	int length = len(str);
	strReverse(str);
	for (int i = 0; i<length; i++)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;

	return 0;
}


#endif

void Reverse_string(string& str)
{
	if (str.size() == 0)
		return;
	char* start = &str[0];
	char* end = &str[str.size() - 1];
	while (start < end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start ++;
		end --;

	}
}
string Reverse_stringstr(string& str)
{
	if (str.size() != 0)
	{
		char* start = &str[0];
		char* end = &str[str.size() - 1];
		while (start < end)
		{
			*start ^= *end;
			*end ^= *start;
			*start ^= *end;
			start++;
			end--;
		}
	}
	return str;
}
void test()
{
	string str = "welcome to cvte";
	Reverse_string(str);	//etvc ot emoclew
	unsigned int i = 0;
	string tmp(str);
	char* start = &tmp[0];
	char* p = start;
	for (i = 0; i < str.size(); ++i)
	{
		cout << str[i];
	}
	cout << endl;
}
int main()
{
	string str1 = "123456789";
	string str2 = "abcdefg";
	Reverse_string(str1);
	unsigned int i = 0;
	for (i = 0; i < str1.size(); ++i)
	{
		cout << str1[i];
	}
	cout << endl;
	cout << Reverse_stringstr(str2) << endl;

	test();
	return 0;
}