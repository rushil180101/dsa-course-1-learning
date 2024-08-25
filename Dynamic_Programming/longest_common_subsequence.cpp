#include <bits/stdc++.h>
using namespace std;

/*
Longest common subsequence
s1 = a p p l e
s2 = a b c d p f l
lcs = a p l --> length = 3
*/
int get_lcs_length(string s1, string s2, int i=0, int j=0)
{
    if (
        (s1.length()==0 || s2.length()==0)
        ||
        (i>=s1.length() || j>=s2.length())
    )
    {
        return 0;
    }
    int ans = 0;
    if (s1[i]==s2[j]) // match
    {
        ans = 1 + get_lcs_length(s1, s2, i+1, j+1);
    }
    else // mismatch
    {
        int l1 = get_lcs_length(s1, s2, i, j+1);
        int l2 = get_lcs_length(s1, s2, i+1, j);
        ans = max(l1, l2);
    }
    return ans;
}

/*
Using DP
*/
int get_lcs_length_dp(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    string s1, s2;

    s1 = "apple";
    s2 = "mango";
    cout << get_lcs_length(s1, s2) << endl; // 1

    s1 = "abcd";
    s2 = "pqrs";
    cout << get_lcs_length(s1, s2) << endl; // 0

    s1 = "apple";
    s2 = "abcpdl";
    cout << get_lcs_length(s1, s2) << endl; // 3

    s1 = "apple";
    s2 = "ample";
    cout << get_lcs_length(s1, s2) << endl; // 4

    // s1 = "pmjghexybyrgzczy";
    // s2 = "hafcdqbgncrcbihkd";
    // cout << get_lcs_length(s1, s2) << endl; // 

    cout << "\n\n===================================\nDP\n";
    
    s1 = "apple";
    s2 = "mango";
    cout << get_lcs_length_dp(s1, s2) << endl; // 1

    s1 = "abcd";
    s2 = "pqrs";
    cout << get_lcs_length_dp(s1, s2) << endl; // 0

    s1 = "apple";
    s2 = "abcpdl";
    cout << get_lcs_length_dp(s1, s2) << endl; // 3

    s1 = "apple";
    s2 = "ample";
    cout << get_lcs_length_dp(s1, s2) << endl; // 4

    s1 = "pmjghexybyrgzczy";
    s2 = "hafcdqbgncrcbihkd";
    cout << get_lcs_length_dp(s1, s2) << endl; // 4

    return 0;
}