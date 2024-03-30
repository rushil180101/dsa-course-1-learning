#include <bits/stdc++.h>
using namespace std;

int multiplication(int m, int n)
{
    if (n <= 1)
    {
        return m;
    }
    return m + multiplication(m, n - 1);
}

int main()
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    cout << "5*4 = " << multiplication(5, 4) << endl; // 20
    cout << "23*1 = " << multiplication(23, 1) << endl; // 23
    cout << "7*8 = " << multiplication(7, 8) << endl; // 56
    cout << "35*14 = " << multiplication(35, 14) << endl; // 490

    return 0;
}
