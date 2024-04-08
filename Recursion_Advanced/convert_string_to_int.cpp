#include <bits/stdc++.h>
using namespace std;

int string_to_int(string s)
{
    if (s == "\0")
    {
        return 0;
    }
    int x = int(s[0]-'0');
    double y = pow(10, s.length()-1);
    return x*y + string_to_int(s.substr(1));
}

int string_to_int_reverse(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int prev = string_to_int_reverse(s.substr(0, s.length()-1));
    return (prev * 10) + (s[s.length()-1] - '0');
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    string s1 = "12345";
    string s2 = "473";
    string s3 = "1";
    string s4 = "0";
    string s5 = "69048";

    cout << s1 << " - " << typeid(s1).name() << endl;

    cout << string_to_int(s1) << " - " << typeid(string_to_int(s1)).name() << endl;
    cout << string_to_int(s2) << " - " << typeid(string_to_int(s2)).name() << endl;
    cout << string_to_int(s3) << " - " << typeid(string_to_int(s3)).name() << endl;
    cout << string_to_int(s4) << " - " << typeid(string_to_int(s4)).name() << endl;
    cout << string_to_int(s5) << " - " << typeid(string_to_int(s5)).name() << endl;

    cout << "\n\nReverse approach\n\n";
    cout << string_to_int_reverse(s1) << " - " << typeid(string_to_int_reverse(s1)).name() << endl;
    cout << string_to_int_reverse(s2) << " - " << typeid(string_to_int_reverse(s2)).name() << endl;
    cout << string_to_int_reverse(s3) << " - " << typeid(string_to_int_reverse(s3)).name() << endl;
    cout << string_to_int_reverse(s4) << " - " << typeid(string_to_int_reverse(s4)).name() << endl;
    cout << string_to_int_reverse(s5) << " - " << typeid(string_to_int_reverse(s5)).name() << endl;
    return 0;
}