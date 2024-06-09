#include <bits/stdc++.h>
using namespace std;

string remove_adjacent_duplicates_v1(string s)
{
    // time complexity = O(n^2)
    bool flag = true;
    while (true)
    {
        flag = true;
        for (int i=0; i<s.length()-1; i++)
        {
            if (s[i] == s[i+1])
            {
                string suffix = "";
                if (i+2 < s.length())
                {
                    suffix = s.substr(i+2, s.length()-(i+2));
                }
                s = s.substr(0, i) + suffix;
                flag = false;
                break;
            }
        }
        if (flag || s.length()==0)
            break;
    }
    if (s.length() == 0)
        return "EMPTY STR";
    return s;
}

string remove_adjacent_duplicates_v2(string s)
{
    // using stack - time complexity = O(n)
    stack<char> char_stack;
    for (int i=0; i<s.length(); i++)
    {
        if (char_stack.empty())
        {
            char_stack.push(s[i]);
            continue;
        }

        if (s[i] == char_stack.top())
        {
            char_stack.pop();
        }
        else
        {
            char_stack.push(s[i]);
        }
    }
    string result = "";
    while (!char_stack.empty())
    {
        result += char_stack.top();
        char_stack.pop();
    }
    if (result.length() == 0)
        return "EMPTY STR";
    reverse(result.begin(), result.end());
    return result;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<string> v1;
    v1.push_back("mississippi"); // m
    v1.push_back("abbaca"); // ca
    v1.push_back("abc"); // abc
    v1.push_back("aab"); // b
    v1.push_back("aaabccddd"); // abd
    v1.push_back("aa"); // empty str
    v1.push_back("baab"); // empty str
    v1.push_back("dabbacd"); // dcd
    v1.push_back("abcddcba"); // empty str
    v1.push_back("pqrssrpq"); // pqpq
    v1.push_back("dbbaaaabbdjcbppqqrssr"); // jcb

    for (int i=0; i<v1.size(); i++)
    {
        cout << remove_adjacent_duplicates_v1(v1[i]) << endl;
    }

    cout << "\n\nStack\n\n";
    for (int i=0; i<v1.size(); i++)
    {
        cout << remove_adjacent_duplicates_v2(v1[i]) << endl;
    }

    return 0;
}