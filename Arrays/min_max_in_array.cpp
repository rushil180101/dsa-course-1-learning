#include <iostream>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int n;
    cin >> n;
    int a[n];
    int smallest = a[0], largest = a[0];
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for (int i=0; i<n; i++)
    {
        if (a[i] > largest) { largest = a[i]; }
        if (a[i] < smallest) { smallest = a[i]; }
    }
    cout << smallest << ", " << largest << endl;

    return 0;
}
