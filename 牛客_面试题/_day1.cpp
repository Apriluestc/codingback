#include <iostream>
#include <vector>
using namespace std;


/*
 利用二维数组由上到下，由左到右递增的规律，
 那么选取右上角或者左下角的元素a[row][col]与target进行比较，
 当target小于元素a[row][col]时，那么target必定在元素a所在行的左边,
 即col--；
 当target大于元素a[row][col]时，那么target必定在元素a所在列的下边,
 即row++；
 *
 int array[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
 * 
 * */


bool find(int key, vector<vector<int> > array)
{
    if(array.empty())
        return false;
    int row = 0;
    int col = array[0].size();
    while(row < array[0].size() && col > 0)
    {
        if(key == array[row][col])
        {
            cout << "true" << endl;
            return true;
        }
        else if(key > array[row][col])
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    //int key = 7;
    //vector<vector<int> > array(_array);
    vector<vector<int> > array(3, vector<int>(3));
    array[0] = {1,2,3};
    array[1] = {4,5,6};
    array[2] = {7,8,9};
    cout << find(7, array) << endl;
    return 0;
}
