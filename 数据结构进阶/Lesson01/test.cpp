#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

void PrintVextor(const vector<int>& v)  //  拷贝构造不期望拷贝,所以加引用 "&"
{
    //普通迭代器 --可读可写
    //const 迭代器 --可读
    //反向迭代器 --反着遍历
    //[)
    vector<int>::const_iterator it = v.begin();
    //vector<int>::const_iterator it = v.begin(); //const 迭代器
    while(it != v.end())
    {
        cout << setw(2) << *it;
        ++it;
    }
    cout << endl;
}

void TestVector()
{
    vector<int> v1; //  定义空对象
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    PrintVextor(v1);
    /*
    vector<int>::iterator it1 = v1.begin();
    while(it1 != v1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
    */
    vector<int> v2(3, 8);
    PrintVextor(v2);
    //迭代器--类似指针的一个对象-----智能指针

}
void PrintList(const list<int> l)
{
    list<int>::const_iterator it = l.begin();
    while(it != l.end())
    {
        cout << setw(2) << *it;
        ++it;
    }
    cout << endl;
}
void TestList()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    PrintList(l1);
}
int main()
{
    TestVector();
    TestList();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

