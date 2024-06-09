#include <bits/stdc++.h>
using namespace std;

bool is_balanced_parenthesis(string input)
{
    stack<char> s;
    for (int i=0; i<input.length(); i++)
    {
        if (input[i]=='(' || input[i]=='{' || input[i]=='[')
        {
            s.push(input[i]);
        }
        else
        {
            if (s.empty())
                return false;
            
            if (
                (s.top()=='(' && input[i]==')')
                || (s.top()=='[' && input[i]==']')
                || (s.top()=='{' && input[i]=='}')
            )
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<string> v;
    v.push_back("()"); // 1
    v.push_back("()[]{}"); // 1
    v.push_back("(]"); // 0
    v.push_back("([)]"); // 0
    v.push_back("{[]}"); // 1
    v.push_back("{[(([{}]))]}[[{}]]"); // 1
    v.push_back("{]]]()[[[}"); // 0
    v.push_back("("); // 0
    v.push_back("}{"); // 0
    v.push_back(""); // 1
    v.push_back("([]{}())"); // 1

    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << " - " << is_balanced_parenthesis(v[i]) << endl;
    }

    return 0;
} 