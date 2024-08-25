#include <bits/stdc++.h>
using namespace std;

/*
Minimum steps to 1
Given the value of n, find the minimum number of steps required to reach 1
Any one of the following can be performed in each step
1. Decrement n by 1
2. If n is divisible by 2, divide n by 2
3. If n is divisible by 3, divide n by 3
*/
int get_min_steps_to_1(int n, int *arr)
{
    if (n<=1)
    {
        return 0;
    }

    // Check if value is already present (resue value and avoid recalculation)
    if (arr[n])
    {
        return arr[n];
    }

    // Value is not present, hence, calculate min steps to 1
    int min_steps_to_1_ndec1 = get_min_steps_to_1(n-1, arr);
    int min_steps_to_1_ndiv2 = n;
    int min_steps_to_1_ndiv3 = n;
    if (n%2 == 0)
    {
        min_steps_to_1_ndiv2 = get_min_steps_to_1(n/2, arr);
    }
    if (n%3 == 0)
    {
        min_steps_to_1_ndiv3 = get_min_steps_to_1(n/3, arr);
    }

    int min_steps = min(
        min_steps_to_1_ndec1,
        min(min_steps_to_1_ndiv2, min_steps_to_1_ndiv3)
    );
    int ans = 1 + min_steps;
    arr[n] = ans;
    return ans;
}

// Get minimum steps to 1 - Iterative approach (bottom up DP)
int get_min_steps_to_1_iterative(int n)
{
    if (n<=1)
    {
        return 0;
    }

    int *arr = new int [n+1];
    arr[0] = 0;
    arr[1] = 0;
    for (int i=2; i<=n; i++)
    {
        int min_steps = arr[i-1];
        if (i%2==0)
        {
            min_steps = min(min_steps, arr[i/2]);
        }
        if (i%3==0)
        {
            min_steps = min(min_steps, arr[i/3]);
        }
        arr[i] = 1 + min_steps;
    }
    int ans = arr[n];
    return ans;
}

int* initialize_array(int n)
{
    int *arr = new int [n+1];
    for (int i=0; i<=n; i++)
        arr[i] = 0;
    return arr;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int n, min_steps_to_1, min_steps_to_1_iterative;
    int *arr;

    n = 10;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 3
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 3

    n = 13;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 4
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 4

    n = 7;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 3
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 3

    n = 9;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 2
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 2

    n = 2;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 1
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 1

    n = 1;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 0
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 0

    n = 11;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 4
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 4

    n = 95;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 8
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 8

    n = 265;
    arr = initialize_array(n);
    min_steps_to_1 = get_min_steps_to_1(n, arr);
    cout << n << " --> " << min_steps_to_1 << endl; // 9
    min_steps_to_1_iterative = get_min_steps_to_1_iterative(n);
    cout << n << " --> " << min_steps_to_1_iterative << endl << endl; // 9

    return 0;
}