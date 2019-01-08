#include "BinaryTree.h"
int main()
{
	int array[10] = { 1, 2, 3, '#', 4, '#', '#', 5, 6 };
	BinaryTree<int> t1(array, sizeof(array) / sizeof(array[0]), '#');
	t1.PrevOrder();
	t1.InOrder();
	t1.LevelOrder();
	t1.Size();
	cout << endl;
	cout << "Size ?" << t1.Size() << endl;
	t1.LeafSize();
	cout << endl;
	//cout << "K Level ?" << t1.GetKLevel(5) << endl;
	cout << "K Depth ?" << t1.Depth() << endl;
	//std::cout << "Hello world" << std::endl;
	t1.Find(6);
	//t1.PostOrderNonR();
	return 0;
}
