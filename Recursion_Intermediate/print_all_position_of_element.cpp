#include <bits/stdc++.h>
using namespace std;

void print_all_idx_position_of_element(int arr[], int n, int e, int i)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == e)
    {
        cout << i << "  ";
    }
    print_all_idx_position_of_element(arr, n, e, i+1);
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

    print_all_idx_position_of_element(a1, 11, 1, 0); // 0 3 4 5
    cout << endl;
    print_all_idx_position_of_element(a1, 11, 2, 0); // 1 7 8 9 10
    cout << endl;
    print_all_idx_position_of_element(a1, 11, 3, 0); // 2 6
    cout << endl;
    print_all_idx_position_of_element(a1, 11, 5, 0); // no output
    cout << endl;

    print_all_idx_position_of_element(a2, 5, 5, 0); // 1 2 4
    cout << endl;
    print_all_idx_position_of_element(a2, 5, 6, 0); // 0 3
    cout << endl;

    print_all_idx_position_of_element(a3, 6, 7, 0); // 4
    cout << endl;
    print_all_idx_position_of_element(a3, 6, 10, 0); // no output
    cout << endl;
    return 0;
}