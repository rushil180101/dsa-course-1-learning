#include <bits/stdc++.h>
using namespace std;

int count_digits(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return 1 + count_digits(n / 10);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    cout << "cd(6478391) = " << count_digits(6478391) << endl; // 7
    cout << "cd(23) = " << count_digits(23) << endl; // 2
    cout << "cd(507) = " << count_digits(507) << endl; // 3
    cout << "cd(934) = " << count_digits(934) << endl; // 3
    cout << "cd(5) = " << count_digits(5) << endl; // 1

    return 0;
}
