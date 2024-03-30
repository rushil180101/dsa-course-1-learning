#include <bits/stdc++.h>
using namespace std;

void binary_search(int a[], int n, int k)
{
    cout << "Array = ";
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int s = 0, e = n - 1;
    int m, i = -1;
    while (s <= e)
    {
        m = s + int((e - s) / 2);
        // Use (s + int((e - s) / 2)) instead of ((s + e) / 2)
        // to prevent integer overflow problem
        // Integer overflow occurs when s + e > INT_MAX

        if (a[m] == k)
        {
            i = m;
            break;
        }

        if (a[m] > k)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    if (i == -1)
    {
        cout << "Key = " << k << " not found";
    }
    else
    {
        cout << "Key = " << k << " found at index = " << i;
    }
    cout << "\n\n";
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    int b[10] = {14, 23, 37, 42, 51, 68, 76, 83, 99, 105};
    int c[5] = {34, 71, 79, 98, 123};

    binary_search(a, 7, 2);
    binary_search(b, 10, 105);
    binary_search(c, 5, 100);

    return 0;
}
