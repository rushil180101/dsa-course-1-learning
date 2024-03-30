#include <iostream>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    /*
    Limitations of cin
    1. Takes any number of chars as input and stores it, thus, leaving no space for null char
    2. It stops taking input when space or tab is encountered
    */

   char a[10];
   cin.getline(a, 5);
   cout << "a = " << a << endl;

   char b[15];
   // cin.getline(array_name, max_size, delimiter)
   cin.getline(b, 15, '8');
   cout << "b = " << b << endl;

    return 0;
}
