#include <bits/stdc++.h>
using namespace std;

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

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    q1.push(60);
    q1.push(70);
    q1.push(80);
    print_q(q1); // 10 to 80

    cout << q1.front() << endl; // 10
    q1.pop();
    cout << q1.front() << endl; // 20
    q1.pop();
    cout << q1.front() << endl; // 30
    q1.pop();
    cout << q1.front() << endl; // 40
    q1.pop();
    cout << q1.front() << endl; // 50
    q1.pop();
    cout << q1.front() << endl; // 60
    q1.pop();
    cout << q1.front() << endl; // 70

    print_q(q1); // 70 80
    cout << q1.size() << endl; // 2
    q1.pop();
    cout << q1.front() << endl; // 80
    print_q(q1); // 80
    cout << q1.size() << endl; // 1
    cout << q1.empty() << endl; // 0

    q1.pop();
    // cout << q1.front() << endl; // cannot get front, q empty
    // q1.pop(); // cannot pop, q empty

    cout << q1.size() << endl; // 0
    cout << q1.empty() << endl; // 1
    print_q(q1); // no output

    return 0;
}