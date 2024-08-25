#include <bits/stdc++.h>
using namespace std;

/*
Given two words word1 and word2, find the min number of operations
to convert word1 to word2
One operation can have any of the following
- insert a character
- remove a character
- replace a character
*/

int get_edit_distance_recursive(string word1, string word2, int i=0, int j=0)
{
    int m = word1.length();
    int n = word2.length();
    if (i>=m || j>=n)
    {
        return max(m-i, n-j);
    }

    if (word1[i]==word2[j])
    {
        return get_edit_distance_recursive(word1, word2, i+1, j+1);
    }

    int ans = min(
        1 + get_edit_distance_recursive(word1, word2, i+1, j+1),
        min(
            1 + get_edit_distance_recursive(word1, word2, i+1, j),
            1 + get_edit_distance_recursive(word1, word2, i, j+1)
        )
    );
    return ans;
}

int get_edit_distance_dp(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    int dp[m+1][n+1];

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i==0 || j==0)
            {
                dp[i][j] = max(i, j);
            }
            else if (word1[i-1]==word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(
                    1 + dp[i-1][j-1],
                    min(1 + dp[i][j-1], 1 + dp[i-1][j])
                );
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

    vector<pair<string, string>> v = {
        make_pair("horse", "ros"), // 3
        make_pair("intention", "execution"), // 5
        make_pair("abcd", "abcde"), // 1
        make_pair("rse", "ros"), // 2
        make_pair("cat", "cat"), // 0
        make_pair("sunday", "saturday"), // 3
        make_pair("geek", "gesek"), // 1
        make_pair("cat", "cut"), // 1
        make_pair("GEEXSFRGEEKKS", "GEEKSFORGEEKS"), // 3
        make_pair("froot", "fruit"), // 2
        // make_pair("dinitrophenylhydrazine", "benzalphenylhydrazone"), // 
    };

    for (auto iter=v.begin(); iter!=v.end(); iter++)
    {
        string word1 = (*iter).first;
        string word2 = (*iter).second;
        int edit_distance = get_edit_distance_recursive(word1, word2);
        int ed_dp = get_edit_distance_dp(word1, word2);
        cout << "Recursive : " << word1 << " --to--> " << word2 << " = " << edit_distance << endl;
        cout << "DP : " << word1 << " --to--> " << word2 << " = " << ed_dp << endl;
        cout << endl;
    }

    string word1 = "dinitrophenylhydrazine";
    string word2 = "benzalphenylhydrazone";
    int ed_dp = get_edit_distance_dp(word1, word2);
    cout << "DP : " << word1 << " --to--> " << word2 << " = " << ed_dp << endl;
    int edit_distance = get_edit_distance_recursive(word1, word2); // Takes too much time due to recursion
    cout << "Recursive : " << word1 << " --to--> " << word2 << " = " << edit_distance << endl;

    return 0;
}