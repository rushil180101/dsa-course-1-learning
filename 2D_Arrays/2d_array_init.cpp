#include <iostream>
#include <iomanip>
using namespace std;

void display_2d_array(int a[][3], int m, int n)
{
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << setw(4) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a[][3] = {
        {1},
        {4, 5},
        {7, 8, 9}
    };
    display_2d_array(a, 3, 3);

    int b[5][3] = {
        {1, 2, 3},
        {4, 5}
    };
    display_2d_array(b, 5, 3);

    // Initialize 2d array with all elements as zero
    int c[3][3] = {{0}};
    display_2d_array(c, 3, 3);

    return 0;
}
