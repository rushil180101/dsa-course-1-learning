#include <iostream>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    char a[10], b[5];
    // Null character '\0' gets appended automatically by cin
    cin >> a;
    cin >> b;

    // cout prints output until it encounters null character \0
    cout << a << endl;
    cout << b << endl;

    return 0;
}
