#include <bits/stdc++.h>
using namespace std;

int get_staircase_count(int n)
{
    if (n <= 3)
    {
        if (n == 3)
        {
            return 4;
        }
        if (n <= 0)
        {
            return 0;
        }
        return n;
    }
    return get_staircase_count(n-1) + get_staircase_count(n-2) + get_staircase_count(n-3);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    cout << "3 -- " << get_staircase_count(3) << endl; // 4
    cout << "4 -- " << get_staircase_count(4) << endl; // 7
    cout << "5 -- " << get_staircase_count(5) << endl; // 13
    cout << "6 -- " << get_staircase_count(6) << endl; // 24
    cout << "10 -- " << get_staircase_count(10) << endl; // 
    cout << "14 -- " << get_staircase_count(14) << endl; // 
    cout << "13 -- " << get_staircase_count(13) << endl; // 
    cout << "2 -- " << get_staircase_count(2) << endl; // 2
    return 0;
}