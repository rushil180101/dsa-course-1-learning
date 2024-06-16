#include <bits/stdc++.h>
using namespace std;

template <class T>
queue<T> reverse_q(queue<T> q)
{
    stack<T> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}

template <class T>
void print_q(queue<T> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;    
}

int main()
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    queue<int> q1;
    queue<char> q2;

    for (int i=1; i<=20; i++)
    {
        q1.push(i);
        q2.push('a' - 1 + i);
    }

    print_q(q1);
    print_q(q2);

    queue<int> rev_q1 = reverse_q(q1);
    queue<char> rev_q2 = reverse_q(q2);

    cout << "\nReversed\n";
    print_q(rev_q1);
    print_q(rev_q2);

    return 0;
}