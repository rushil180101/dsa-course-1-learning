#include <bits/stdc++.h>
using namespace std;

bool is_element_present(int arr[], int n, int e)
{
    static int i = 0;
    if (arr[i] == e)
    {
        return true;
    }
    if (i == n - 1)
    {
        return false;
    }
    i++;
    return is_element_present(arr, n, e);
}

bool is_element_present_v2(int arr[], int n, int e)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == e)
    {
        return true;
    }
    return is_element_present_v2(arr+1, n-1, e);
}

// Approach - 2 : Check array elements from right to left
bool is_element_present_rtl(int arr[], int n, int e)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[n-1] == e)
    {
        return true;
    }
    return is_element_present_rtl(arr, n-1, e);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int arr1[5] = {64, 72, 35, 10, 23};
    int arr2[8] = {1, 8, 5, 6, 7, 3, 4, 2};
    int arr3[10] = {19, 327, 834, 28, 41, 64, 14, 87, 65, 86};
    int arr4[3] = {9, 1, 3};

    cout << "10 - arr1 - " << is_element_present(arr1, 5, 10) << endl; // 1
    cout << "9  - arr2 - " << is_element_present(arr2, 8, 9) << endl; // 0
    cout << "25 - arr3 - " << is_element_present(arr3, 10, 25) << endl; // 0
    cout << "3  - arr4 - " << is_element_present(arr4, 3, 3) << endl; // 1

    cout << "\n\nV2\n";
    cout << "10 - arr1 - " << is_element_present_v2(arr1, 5, 10) << endl; // 1
    cout << "9  - arr2 - " << is_element_present_v2(arr2, 8, 9) << endl; // 0
    cout << "25 - arr3 - " << is_element_present_v2(arr3, 10, 25) << endl; // 0
    cout << "3  - arr4 - " << is_element_present_v2(arr4, 3, 3) << endl; // 1

    cout << "\n\nRTL\n";
    cout << "10 - arr1 - " << is_element_present_rtl(arr1, 5, 10) << endl; // 1
    cout << "9  - arr2 - " << is_element_present_rtl(arr2, 8, 9) << endl; // 0
    cout << "25 - arr3 - " << is_element_present_rtl(arr3, 10, 25) << endl; // 0
    cout << "3  - arr4 - " << is_element_present_rtl(arr4, 3, 3) << endl; // 1
    return 0;
}
