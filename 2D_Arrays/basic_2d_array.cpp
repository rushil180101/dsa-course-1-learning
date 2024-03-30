#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int x, y;
    cin >> x >> y;

    int a[x][y];
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            cin >> a[i][j];
        }
    }

    // Row wise
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            cout << setw(4) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Column wise
    for (int j=0; j<y; j++)
    {
        for (int i=0; i<x; i++)
        {
            cout << setw(4) << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
