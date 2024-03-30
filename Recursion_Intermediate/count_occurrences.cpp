#include <bits/stdc++.h>
using namespace std;

int count_occurrences(int arr[], int n, int e, int count)
{
    if (n == 0)
    {
        return count;
    }
    if (arr[0] == e)
    {
        count++;
    }
    return count_occurrences(arr+1, n-1, e, count);
}

int count_occurrences_2(int arr[], int n, int e)
{
    if (n == 0)
    {
        return 0;
    }
    return (arr[0] == e) + count_occurrences_2(arr+1, n-1, e);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int a1[11] = {1, 2, 3, 1, 1, 1, 3, 2, 2, 2, 2};
    int a2[5] = {6, 5, 5, 6, 5};
    int a3[6] = {4, 3, 9, 6, 7, 1};

    cout << count_occurrences(a1, 11, 1, 0) << endl; // 4
    cout << count_occurrences(a1, 11, 2, 0) << endl; // 5
    cout << count_occurrences(a1, 11, 3, 0) << endl; // 2
    cout << count_occurrences(a1, 11, 4, 0) << endl; // 0

    cout << count_occurrences(a2, 5, 5, 0) << endl; // 3
    cout << count_occurrences(a2, 5, 6, 0) << endl; // 2
    cout << count_occurrences(a2, 5, 10, 0) << endl; // 0

    cout << count_occurrences(a3, 6, 9, 0) << endl; // 1
    cout << count_occurrences(a3, 6, 5, 0) << endl; // 0
    cout << count_occurrences(a3, 6, 1, 0) << endl; // 1

    cout << "\n\nApproach 2\n";
    cout << count_occurrences_2(a1, 11, 1) << endl; // 4
    cout << count_occurrences_2(a1, 11, 2) << endl; // 5
    cout << count_occurrences_2(a1, 11, 3) << endl; // 2
    cout << count_occurrences_2(a1, 11, 4) << endl; // 0

    cout << count_occurrences_2(a2, 5, 5) << endl; // 3
    cout << count_occurrences_2(a2, 5, 6) << endl; // 2
    cout << count_occurrences_2(a2, 5, 10) << endl; // 0

    cout << count_occurrences_2(a3, 6, 9) << endl; // 1
    cout << count_occurrences_2(a3, 6, 5) << endl; // 0
    cout << count_occurrences_2(a3, 6, 1) << endl; // 1
    return 0;
}