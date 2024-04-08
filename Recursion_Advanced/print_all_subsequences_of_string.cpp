#include <bits/stdc++.h>
using namespace std;

void print_subsequences(string s, string output="")
{
    if (s.length() == 0)
    {
        cout << output << endl;
        return;
    }
    // Include first char in the output of subsequences of remaining array/str
    print_subsequences(s.substr(1), output + s[0]);

    // Exclude first char in the output of subsequences of remaining array/str
    // i.e. print output of subsequences as is
    print_subsequences(s.substr(1), output);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    string s = "abc";
    print_subsequences(s);
    return 0;
}