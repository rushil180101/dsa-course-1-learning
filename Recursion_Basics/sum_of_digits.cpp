#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int n)
{
    if (n / 10 == 0)
    {
        return n;
    }
    int s = (n % 10) + sum_of_digits(n / 10);
    return s;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    cout << "sum_of_digits(12345) = " << sum_of_digits(12345) << endl; // 15
    cout << "sum_of_digits(7098) = " << sum_of_digits(7098) << endl; // 24
    cout << "sum_of_digits(1) = " << sum_of_digits(1) << endl; // 1
    cout << "sum_of_digits(59283) = " << sum_of_digits(59283) << endl; // 27
    cout << "sum_of_digits(20) = " << sum_of_digits(20) << endl; // 2

    return 0;
}
