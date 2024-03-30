#include <bits/stdc++.h>
using namespace std;

int count_zeros(int n)
{
    int z = 0;
    int r = (n % 10);
    if (r == 0)
    {
        z++;
    }
    if (int(n/10) == 0)
    {
        return 0;
    }
    return z + count_zeros(n / 10);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a = 10002350, b = 501403, c = 891, d = 1406;
    cout << "a = " << a << ", zeros = " << count_zeros(a) << endl; // 4
    cout << "b = " << b << ", zeros = " << count_zeros(b) << endl; // 2
    cout << "c = " << c << ", zeros = " << count_zeros(c) << endl; // 0
    cout << "d = " << d << ", zeros = " << count_zeros(d) << endl; // 1
    return 0;
}
