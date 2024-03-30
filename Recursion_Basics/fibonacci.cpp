#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    cout << "fib(0) = " << fib(0) << endl; // 0
    cout << "fib(1) = " << fib(1) << endl; // 1
    cout << "fib(-5) = " << fib(-5) << endl; // -1
    cout << "fib(5) = " << fib(5) << endl; // 5
    cout << "fib(8) = " << fib(8) << endl; // 21
    cout << "fib(9) = " << fib(9) << endl; // 34
    cout << "fib(10) = " << fib(10) << endl; // 55

    return 0;
}
