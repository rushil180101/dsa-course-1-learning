#include <bits/stdc++.h> // Master header file
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a[7] = {23, 17, 45, 11, 9, 56, 78};
    for (int i=0; i<7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(a, a + 7); // Inbuilt sort - present in <algorithm> header file

    for (int i=0; i<7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
