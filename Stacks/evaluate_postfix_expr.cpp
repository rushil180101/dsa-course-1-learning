#include <bits/stdc++.h>
using namespace std;

int evaluate_postfix_expr(vector<string> postfix_expr)
{
    // Postfix expr is also known as reverse polish notation
    // Calculators first convert infix to postfix and then evaluate
    stack<int> s;
    for (int i=0; i<postfix_expr.size(); i++)
    {
        if (
            postfix_expr[i] == "+"
            || postfix_expr[i] == "-"
            || postfix_expr[i] == "*"
            || postfix_expr[i] == "/"
        )
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            int c = 0;
            switch (postfix_expr[i][0])
            {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    c = a / b;
                    break;
                default:
                    break;
            }
            s.push(c);
        }
        else
        {
            s.push(stoi(postfix_expr[i]));
        }
    }
    return s.top();
}

int main()
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<string> postfix_exp1{"1", "2", "+", "3", "*", "5", "+"};
    vector<string> postfix_exp2{"4", "13", "5", "/", "+"};
    vector<string> postfix_exp3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    vector<string> postfix_exp4{"1", "1", "+"};

    cout << evaluate_postfix_expr(postfix_exp1) << endl; // 14
    cout << evaluate_postfix_expr(postfix_exp2) << endl; // 6
    cout << evaluate_postfix_expr(postfix_exp3) << endl; // 22
    cout << evaluate_postfix_expr(postfix_exp4) << endl; // 2

    return 0;
}