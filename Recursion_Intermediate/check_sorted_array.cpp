#include <bits/stdc++.h>
using namespace std;

// Approach - 1
bool check_sorted_array(int arr[], int n)
{
    // Base case
    if (n <= 1)
    {
        return true;
    }

    int last_element = arr[n-1];
    // Check if last element is greater than all the previous elements
    bool flag = true;
    for (int i=0; i<n-1; i++)
    {
        if (arr[i] > last_element)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        return false;
    }
    return flag && check_sorted_array(arr, n-1);
}

// Approach - 2
bool check_sorted_array_op(int arr[], int n)
{
    // Base case
    if (n <= 1)
    {
        return true;
    }

    // No need to compare last element with all preceding elements
    // Just compare it with previous element
    if (arr[n-2] > arr[n-1])
    {
        return false;
    }
    return check_sorted_array_op(arr, n-1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    // This problem can be solved or broken down into smaller problem as follows
    // 1. Left to right - Take first element, then solve for righter array
    // 2. Right to left - Take last element, then solve for left array

    int arr1[5] = {1, 2, 3, 4, 5}; // T
    int arr2[10] = {0, 5, 19, 23, 28, 29, 52, 78, 90, 96}; // T
    int arr3[3] = {23, 11, 51}; // F
    int arr4[7] = {-5, 11, -2, 0, 1, 98, 21}; // F
    int arr5[7] = {-19, -6, -3, 0, 25, 108, 110}; // T
    int arr6[6] = {1, 1, 1, 1, 1, 2}; // T
    int arr7[3] = {0, 0, 0}; // T
    int arr8[8] = {9, 2, 3, 4, 5, 6, 7, 8}; // F

    cout << check_sorted_array(arr1, 5) << endl; // 1
    cout << check_sorted_array(arr2, 10) << endl; // 1
    cout << check_sorted_array(arr3, 3) << endl; // 0
    cout << check_sorted_array(arr4, 7) << endl; // 0
    cout << check_sorted_array(arr5, 7) << endl; // 1
    cout << check_sorted_array(arr6, 6) << endl; // 1
    cout << check_sorted_array(arr7, 3) << endl; // 1
    cout << check_sorted_array(arr8, 8) << endl; // 0

    // Optimised
    cout << "\n\nOptimised\n\n";

    int op_arr1[5] = {1, 2, 3, 4, 5}; // T
    int op_arr2[10] = {0, 5, 19, 23, 28, 29, 52, 78, 90, 96}; // T
    int op_arr3[3] = {23, 11, 51}; // F
    int op_arr4[7] = {-5, 11, -2, 0, 1, 98, 21}; // F
    int op_arr5[7] = {-19, -6, -3, 0, 25, 108, 110}; // T
    int op_arr6[6] = {1, 1, 1, 1, 1, 2}; // T
    int op_arr7[3] = {0, 0, 0}; // T
    int op_arr8[8] = {9, 2, 3, 4, 5, 6, 7, 8}; // F

    cout << check_sorted_array_op(op_arr1, 5) << endl; // 1
    cout << check_sorted_array_op(op_arr2, 10) << endl; // 1
    cout << check_sorted_array_op(op_arr3, 3) << endl; // 0
    cout << check_sorted_array_op(op_arr4, 7) << endl; // 0
    cout << check_sorted_array_op(op_arr5, 7) << endl; // 1
    cout << check_sorted_array_op(op_arr6, 6) << endl; // 1
    cout << check_sorted_array_op(op_arr7, 3) << endl; // 1
    cout << check_sorted_array_op(op_arr8, 8) << endl; // 0

    return 0;
}
