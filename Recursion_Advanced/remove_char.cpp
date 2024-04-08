#include <bits/stdc++.h>
#include <cstring>
using namespace std;

string remove_char(string s, char c)
{
    if (s.length() <= 0)
    {
        return "";
    }
    string first_char;
    if (s[0] == c)
    {
        first_char = "";
    }
    else
    {
        first_char = s[0];
    }
    return first_char + remove_char(s.substr(1), c);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    string s1 = "abcdaxyz";
    string s2 = remove_char(s1, 'a');
    cout << s1 << endl; // abcdaxyz
    cout << s2 << endl; // bcdxyz

    s1 = "hhhhpqrsh";
    s2 = remove_char(s1, 'h');
    cout << s1 << endl; // hhhhpqrsh
    cout << s2 << endl; // pqrs

    s1 = "lmnop";
    s2 = remove_char(s1, 'a');
    cout << s1 << endl; // lmnop
    cout << s2 << endl; // lmnop
    return 0;
}