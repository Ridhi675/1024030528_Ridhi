/*2) Design the logic to remove the duplicate elements from an Array and
after the deletion the array should contain the unique elements*/
#include <bits/stdc++.h>
using namespace std;

void deleteEle(int arr[100], int &n, int pos)
{
    if (n == 0)
    {
        cout << "Array is empty\n";
        return;
    }
    if (pos < 0 || pos >= n)
    {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main()
{
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array Before Removing Duplicates:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                deleteEle(arr, n, j);
                j--; // stay at same index to check new shifted element
            }
        }
    }

    cout << "\nArray after Removing Duplicates:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
