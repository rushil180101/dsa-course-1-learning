#include <iostream>
#include <cstring>
using namespace std;

void print_all_prefixes(char a[])
{
    for (int i=0; i<strlen(a); i++)
    {
        for (int j=0; j<=i; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

void print_all_suffixes(char a[])
{
    int len = strlen(a);
    for (int i=0; i<len; i++)
    {
        for (int j=len-1-i; j<len; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    char a[100];
    cin.getline(a, 100);

    print_all_prefixes(a);
    cout << endl;
    print_all_suffixes(a);

    return 0;
}
