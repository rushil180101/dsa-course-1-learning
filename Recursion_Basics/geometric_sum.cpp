#include <bits/stdc++.h>
using namespace std;

double geometric_sum(int k)
{
    if (k <= 0)
    {
        return 1.0;
    }
    return (1.0 / pow(2, k)) + geometric_sum(k - 1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int k;

    k = 3;
    cout << "k = " << k << ", geometric sum = " << geometric_sum(k) << endl; //

    k = 2;
    cout << "k = " << k << ", geometric sum = " << geometric_sum(k) << endl; //

    k = 5;
    cout << "k = " << k << ", geometric sum = " << geometric_sum(k) << endl; //

    k = 9;
    cout << "k = " << k << ", geometric sum = " << geometric_sum(k) << endl; //

    k = 0;
    cout << "k = " << k << ", geometric sum = " << geometric_sum(k) << endl; //

    return 0;
}
