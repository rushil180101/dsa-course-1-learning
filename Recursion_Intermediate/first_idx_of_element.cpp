#include <bits/stdc++.h>
using namespace std;

int first_idx_of_element(int arr[], int n, int e, int i)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[i] == e)
    {
        return i;
    }
    return first_idx_of_element(arr, n-1, e, i+1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[5] = {5, 4, 3, 2, 1};
    int a3[6] = {1, 2, 3, 7, 7, 3};
    int a4[3] = {25, 38, 79};

    cout << first_idx_of_element(a1, 10, 7, 0) << endl; // 6
    cout << first_idx_of_element(a2, 5, 4, 0) << endl; // 1
    cout << first_idx_of_element(a3, 6, 3, 0) << endl; // 2
    cout << first_idx_of_element(a3, 6, 7, 0) << endl; // 3
    cout << first_idx_of_element(a4, 3, 40, 0) << endl; // -1
    return 0;
}
