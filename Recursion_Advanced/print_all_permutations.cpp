#include <bits/stdc++.h>
using namespace std;

void print_all_permutations(string s, string output="")
{
    if (s.length() == 0)
    {
        cout << output << endl;
        return;
    }
    for (int i=0; i<s.length(); i++)
    {
        print_all_permutations(
            s.substr(0, i) + s.substr(i+1, s.length()-i),
            output + s[i]
        );
    }
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    string s1 = "ABCD";
    print_all_permutations(s1);
    return 0;
}