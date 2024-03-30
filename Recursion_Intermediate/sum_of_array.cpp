#include <bits/stdc++.h>
using namespace std;

int sum_of_array(int arr[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return arr[n-1] + sum_of_array(arr, n-1);
}

int sum_of_array_ltr(int arr[], int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return arr[0] + sum_of_array_ltr(arr+1, n-1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[8] = {-4, -3, -2, -1, 1, 2, 3, 4};
    int arr3[3] = {0, 0, -1};

    cout << sum_of_array(arr1, 5) << endl; // 15
    cout << sum_of_array(arr2, 8) << endl; // 0
    cout << sum_of_array(arr3, 3) << endl; // -1

    cout << "\n\nLeft to right\n\n";
    int ltr_arr1[5] = {1, 2, 3, 4, 5};
    int ltr_arr2[8] = {-4, -3, -2, -1, 1, 2, 3, 4};
    int ltr_arr3[3] = {0, 0, -1};

    cout << sum_of_array_ltr(ltr_arr1, 5) << endl; // 15
    cout << sum_of_array_ltr(ltr_arr2, 8) << endl; // 0
    cout << sum_of_array_ltr(ltr_arr3, 3) << endl; // -1
    return 0;
}
