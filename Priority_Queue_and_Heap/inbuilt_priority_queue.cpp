#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    // Default priority queue - uses max heap (descending order)
    priority_queue<int> max_pq1;
    max_pq1.push(56);
    max_pq1.push(78);
    max_pq1.push(18);
    max_pq1.push(43);
    max_pq1.push(97);
    max_pq1.push(12);
    max_pq1.push(35);

    cout << "Size = " << max_pq1.size() << endl;
    while (!max_pq1.empty())
    {
        int x = max_pq1.top();
        max_pq1.pop();
        cout << "Popped (max) = " << x << endl;
    }
    cout << "\n\n";

    // Create min priority queue - Min heap (ascending order)
    priority_queue<int, vector<int>, greater<int>> min_pq1;
    min_pq1.push(6);
    min_pq1.push(7);
    min_pq1.push(3);
    min_pq1.push(8);
    min_pq1.push(0);
    min_pq1.push(2);
    min_pq1.push(1);
    min_pq1.push(4);
    min_pq1.push(9);
    min_pq1.push(5);
    cout << "Size (min pq) = " << min_pq1.size() << endl;
    while (!min_pq1.empty())
    {
        cout << min_pq1.top() << " ";
        min_pq1.pop();
    }
    cout << "\n\n";
    return 0;
}