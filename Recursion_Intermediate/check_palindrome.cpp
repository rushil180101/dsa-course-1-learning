#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(int arr[], int s, int e)
{
    if (s >= e)
    {
        return true;
    }
    if (arr[s] == arr[e])
    {
        return check_palindrome(arr, s+1, e-1);
    }
    return false;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a1[7] = {1, 2, 3, 4, 3, 2, 1};
    int a2[8] = {1, 2, 3, 4, 3, 3, 2, 1};
    int a3[10] = {1, 1, 1, 5, 20, 20, 5, 1, 1, 1};

    cout << check_palindrome(a1, 0, 6) << endl; // 1
    cout << check_palindrome(a2, 0, 7) << endl; // 0
    cout << check_palindrome(a3, 0, 9) << endl; // 1

    return 0;
}