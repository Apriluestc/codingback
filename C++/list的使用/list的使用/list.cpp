#include <iostream>

#include <list>
#include <vector>
using namespace std;

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l1(0);
	list<int> l2 = { 1, 2, 3, 4, 5, 6 };
	for (const auto e : l2)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << l1.size() << endl;
	return 0;
}