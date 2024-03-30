#include <iostream>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a, b, p, q, x, y;
    cin >> a >> b >> p >> q >> x >> y;

    cout << a << ", " << b << endl;
    // XOR
    a = a ^ b;
    b = b ^ a;
    a = b ^ a;
    cout << a << ", " << b << endl;

    cout << p << ", " << q << endl;
    // Add/Sub
    p = p + q;
    q = p - q;
    p = p - q;
    cout << p << ", " << q << endl;

    cout << x << ", " << y << endl;
    swap(x, y);
    cout << x << ", " << y << endl;


    return 0;
}
