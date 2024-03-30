#include <bits/stdc++.h>
using namespace std;

void print_numbers(int n)
{
    if (n < 1)
    {
        cout << -1;
        return;
    }
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    print_numbers(n - 1);
    cout << n << " ";
}

void print_numbers_descending(int n)
{
    if (n < 1)
    {
        cout << -1;
        return;
    }
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    print_numbers_descending(n - 1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    print_numbers(10);
    cout << endl << endl;

    print_numbers(1);
    cout << endl << endl;

    print_numbers(0);
    cout << endl << endl;

    print_numbers(7);
    cout << endl << endl;

    cout << "Print descending" << endl;

    print_numbers_descending(10);
    cout << endl << endl;

    print_numbers_descending(1);
    cout << endl << endl;

    print_numbers_descending(0);
    cout << endl << endl;

    print_numbers_descending(7);
    cout << endl << endl;

    return 0;
}
