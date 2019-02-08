#include <iostream>
using namespace std;
#include <Windows.h>
#include <stdlib.h>
static int g_value = 10;
char* ptr = nullptr;
void test_func()
{}
DWORD WINAPI thread_entry(LPVOID lpThreadParameter)
{
	g_value = 9;
	ptr[0] = 10;
	test_func();
	while (1)
	{
		cout << "thread called" << endl;
		Sleep(3000);
	}
	return 0;
}
int main(int argc, char** argv)
{
	ptr = (char*)malloc(100);
	int threadid;
	HANDLE h = CreateThread(nullptr, 0, thread_entry, nullptr, 0, (LPDWORD)&threadid);
	test_func();
	while (1)
	{
		cout << "main thread" << endl;
		Sleep(5000);
	}
	return 0;
}