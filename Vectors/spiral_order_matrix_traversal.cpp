#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int m, n;
    cin >> m >> n;

    int matrix[m][n];
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << endl << "Original matrix" << endl;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Spiral order" << endl;

    // Spiral order traversal
    int a = 0, b = 0, p = 0, q = -1, x = m, y = n;
    bool incr_row = false, incr_col = true;
    bool decr_row = false, decr_col = false;

    while (true)
    {
        if ((p >= x) || (q >= y))
        {
            break;
        }

        if (incr_col)
        {
            while (b < y)
            {
                cout << setw(5) << matrix[a][b] << " ";
                b++;
            }
            a++;
            b--;
            y--;
            incr_row = true;
            incr_col = false;
            decr_row = false;
            decr_col = false;
            continue;
        }

        if (incr_row)
        {
            while (a < x)
            {
                cout << setw(5) << matrix[a][b] << " ";
                a++;
            }
            a--;
            b--;
            x--;
            incr_row = false;
            incr_col = false;
            decr_row = false;
            decr_col = true;
            continue;
        }

        if (decr_col)
        {
            while (b > q)
            {
                cout << setw(5) << matrix[a][b] << " ";
                b--;
            }
            a--;
            b++;
            q++;
            incr_row = false;
            incr_col = false;
            decr_row = true;
            decr_col = false;
            continue;
        }

        if (decr_row)
        {
            while (a > p)
            {
                cout << setw(5) << matrix[a][b] << " ";
                a--;
            }
            a++;
            b++;
            p++;
            incr_row = false;
            incr_col = true;
            decr_row = false;
            decr_col = false;
            continue;
        }
    }

    return 0;
}
