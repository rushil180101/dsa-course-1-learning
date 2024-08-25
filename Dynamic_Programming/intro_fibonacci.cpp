#include <bits/stdc++.h>
using namespace std;

int get_nth_fibonacci(int n, int *arr)
{
    if (n==0 || n==1)
    {
        return n;
    }

    // Check if nth fib is already stored
    if (arr[n])
    {
        return arr[n];
    }

    // nth fib is not present, so calculating for first time
    int nth_fib = get_nth_fibonacci(n-1, arr) + get_nth_fibonacci(n-2, arr);
    // Store it for future reuse
    arr[n] = nth_fib;
    return nth_fib;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int n;
    cin >> n;

    int *arr = new int [n+1];
    for (int i=0; i<=n; i++)
        arr[i] = 0;
    
    int nth_fib = get_nth_fibonacci(n, arr);
    cout << n << "(nth) fib = " << setw(4) << nth_fib << endl;

    return 0;
}