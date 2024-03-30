#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int n = 10;
    char a[n];
    cin.getline(a, n);
    cout << "Actual = " << a << endl;
    int null_char_idx = 0;
    for (int i=0; i<n; i++)
    {
        if (a[i] == '\0')
        {
            null_char_idx = i;
            break;
        }
    }
    for (int i=0; i<null_char_idx/2; i++)
    {
        swap(a[i], a[null_char_idx-1-i]);
    }
    cout << "Reversed = " << a << endl;

    char str1[100];
    cin.getline(str1, 100);
    cout << "Actual = " << str1 << endl;
    strrev(str1);
    cout << "Reversed = " << str1 << endl;

    string str2;
    cin >> str2; // Here delimiter is whitespace
    cout << "Actual = " << str2 << endl;
    reverse(str2.begin(), str2.end());
    cout << "Reversed = " << str2 << endl;

    return 0;
}
