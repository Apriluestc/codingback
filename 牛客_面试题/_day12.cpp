#include <iostream>
using namespace std;
#include <vector>


/*
 * int array = {
 *               1,  2,  3,  4,
 *               5,  6,  7,  8,
 *               9, 10, 11, 12,
 *              13, 14, 15, 15,
 *                              }
 * 
 *输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字
 * */


vector<int> printMatrix(vector<vector<int> > matrix)
{
    vector<int> res;
    res.clear();
    int row = matrix.size();
    int col = matrix[0].size();
    int circle = ((row < col ? row : col) - 1) / 2 + 1;
    for(int i = 0;i < circle;i++)
    {
        //从左往右打印
        for(int j = i;j < col - i;j++)
            res.push_back(matrix[i][j]);
        //从上往下打印
        for(int k = i + 1;k < row - i;k++)
            res.push_back(matrix[k][col - i - 1]);
        //从右往左打印
        for(int m = col - i - 2;(m >= i) && (row - i - 1 != i);m--)
            res.push_back(matrix[row - i - 1][m]);
        for(int n = row - i - 2;(n > i) && (col - i - 1 != i);n--)
            res.push_back(matrix[n][i]);
    }
    return res;
}

/*
void reverseArray(vector<vector<int> > array)
{
    vector<int> res;
    res.clear();
    int row = array.size();
    int col = array[0].size();
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < row;j++)
        {
            swap(array[i][j], array[j][i]);
        }
    }
}
*/

int main()
{
    vector<int> result;
    vector<vector<int> > num1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    result = printMatrix(num1);
    for(int i = 0;i < result.size();i++)
        cout << result[i] << " ";
    cout << endl;
    vector<vector<int> > num2 = {{1,2},{3,4}};
    
    
    //printMatrix(num2);
    vector<int> res;
    res = printMatrix(num2);
    for(int i = 0;i < res.size();i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
