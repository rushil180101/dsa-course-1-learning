#include <bits/stdc++.h>
using namespace std;

vector<string> get_all_subsequences(string s)
{
    if ((s.length() == 0) || (s == "\0"))
    {
        vector<string> empty_vector;
        return empty_vector;
    }
    vector<string> prev_subsequences = get_all_subsequences(s.substr(1));
    vector<string> new_subsequences;
    for (int i=0; i<2; i++)
    {
        string first_letter;
        if (i == 0)
        {
            first_letter = s[0];
        }
        else
        {
            first_letter = "";
        }
        for (
            vector<string>::iterator iter=prev_subsequences.begin();
            iter!=prev_subsequences.end();
            iter++
        )
        {
            string output = first_letter + *iter;
            new_subsequences.push_back(output);
        }
    }
    string x;
    x = s[0];
    new_subsequences.push_back(x);
    return new_subsequences;
}

void store_all_subsequences_approach_2(string s, string output, vector<string> &v)
{
    if ((s.length() == 0) || (s == "\0"))
    {
        v.push_back(output);
        return;
    }
    // Include first character in the output of all subsequences in remaining string
    store_all_subsequences_approach_2(s.substr(1), output + s[0], v);
    // Exclude first character from the ouptut of all subsequences in remaining string
    store_all_subsequences_approach_2(s.substr(1), output, v);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    string s1 = "abcd";
    vector<string> v1 = get_all_subsequences(s1);
    sort(v1.begin(), v1.end());
    for (
        vector<string>::iterator iter=v1.begin();
        iter!=v1.end();
        iter++
    )
    {
        cout << *iter << endl;
    }

    cout << "\n\nApproach - 2\n\n";
    string s2 = "pqrs", output = "";
    vector<string> v2;
    store_all_subsequences_approach_2(s2, output, v2);
    for (int i=0; i<v2.size(); i++)
    {
        cout << v2[i] << endl;
    }
    return 0;
}