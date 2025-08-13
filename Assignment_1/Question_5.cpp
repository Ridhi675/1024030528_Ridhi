/*5) Write a program to find sum of every row and every column in a two-dimensional array.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter no of rows and columns: " << endl;
    cin >> row >> col;
    int a[row][col];
    cout << "Enter elements in " << row << "*" << col << " matrix : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        int rowsum = 0;
        for (int j = 0; j < col; j++)
        {
            rowsum += a[i][j];
        }
        cout << "Row " << i + 1 << " Sum is : " << rowsum << endl;
    }

    for (int j = 0; j < col; j++)
    {
        int colsum = 0;
        for (int i = 0; i < row; i++)
        {
            colsum += a[i][j];
        }
        cout << "Column " << j + 1 << " Sum is : " << colsum << endl;
    }
}