#include <bits/stdc++.h>
using namespace std;

int last_idx_of_element(int arr[], int n, int e, int i)
{
    if (i < 0)
    {
        return -1;
    }
    if (arr[i] == e)
    {
        return i;
    }
    return last_idx_of_element(arr, n, e, i-1);
}

int last_idx_of_element_optimised(int arr[], int n, int e)
{
    if (n <= 0)
    {
        return -1;
    }
    if (arr[n-1] == e)
    {
        return n-1;
    }
    return last_idx_of_element_optimised(arr, n-1, e);
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

    cout << last_idx_of_element(a1, 10, 7, 9) << endl; // 6
    cout << last_idx_of_element(a2, 5, 4, 4) << endl; // 1
    cout << last_idx_of_element(a3, 6, 3, 5) << endl; // 5
    cout << last_idx_of_element(a3, 6, 7, 5) << endl; // 4
    cout << last_idx_of_element(a4, 3, 40, 2) << endl; // -1

    cout << "\n\nWithout using index variable - i\n";
    cout << last_idx_of_element_optimised(a1, 10, 7) << endl; // 6
    cout << last_idx_of_element_optimised(a2, 5, 4) << endl; // 1
    cout << last_idx_of_element_optimised(a3, 6, 3) << endl; // 5
    cout << last_idx_of_element_optimised(a3, 6, 7) << endl; // 4
    cout << last_idx_of_element_optimised(a4, 3, 40) << endl; // -1

    return 0;
}