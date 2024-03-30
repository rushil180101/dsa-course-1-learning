#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    if (n <= 0)
    {
        return 1;
    }
    return x * power(x, n - 1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    cout << "5^4 = " << power(5, 4) << endl; // 625
    cout << "10^5 = " << power(10, 5) << endl; // 100000
    cout << "7^2 = " << power(7, 2) << endl; // 49
    cout << "20^0 = " << power(20, 0) << endl; // 1
    cout << "3^1 = " << power(3, 1) << endl; // 3
    cout << "11^-3 = " << power(11, -3) << endl; // 1

    return 0;
}
