#include <iostream>
#include <iomanip>
using namespace std;

// Display 2d array without passing static column number
void display_2d_array(int *a[], int x, int y)
{
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            cout << setw(4) << (*a[i]) + j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Flatten 2d array without passing static column number
int* flatten_2d_array(int *a[], int x, int y)
{
    int *flattened = new int [x * y];
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            *((flattened + i*y) + j) = (*a[i]) + j;
        }
    }
    return flattened;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int x, y;
    cin >> x >> y;

    int a[x][y];
    int *p[x];
    for (int i=0; i<x; i++)
    {
        p[i] = a[i];
    }

    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            cin >> a[i][j];
        }
    }
    display_2d_array(p, x, y);

    int *flattened_array = flatten_2d_array(p, x, y);
    cout << "Flattened array" << endl;
    for (int i=0; i<x*y; i++)
    {
        cout << *(flattened_array + i) << " ";
    }
    cout << endl;

    return 0;
}
