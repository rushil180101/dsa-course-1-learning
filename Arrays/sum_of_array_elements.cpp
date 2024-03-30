#include <iostream>
using namespace std;

int main()
{
    // #################### //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // #################### //
    int n, s = 0;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    cout << s << endl;
    return 0;
}
