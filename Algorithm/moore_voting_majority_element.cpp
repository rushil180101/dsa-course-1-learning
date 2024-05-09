#include <bits/stdc++.h>
using namespace std;

// Moore voting algorithm
int find_majority_element(int arr[], int n)
{
    int e = arr[0];
    int c = 1;
    for (int i=1; i<n; i++)
    {
        if (arr[i] == e)
        {
            c++;
        }
        else
        {
            c--;
            if (c == 0)
            {
                e = arr[i];
                c++;
            }
        }
    }
    return e;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int arr1[] = {8, 1, 8, 8, 9, 8, 6, 8, 3};
    int arr2[] = {1, 1, 1, 2, 3, 4, 1, 1, 5, 1, 6, 1, 1, 7};
    int arr3[] = {10, 10, 3, 3, 3};
    int arr4[] = {6, 7, 6, 7, 7};

    cout << find_majority_element(arr1, 9) << endl; // 8
    cout << find_majority_element(arr2, 14) << endl; // 1
    cout << find_majority_element(arr3, 5) << endl; // 3
    cout << find_majority_element(arr4, 5) << endl; // 7
    return 0;
}