#include <bits/stdc++.h>
using namespace std;

void print_char_array(char arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    cout << arr[0] << " ";
    print_char_array(arr+1, n-1);
}

void print_rev_char_array(char arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    cout << arr[n-1] << " ";
    print_rev_char_array(arr, n-1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    char arr1[5] = {'a', 'b', 'c', 'd', 'e'};
    char arr2[8] = {'x', 'p', 'k', 'z', 'a', 'w', 'p', 'h'};
    char arr3[] = {'r'};

    print_char_array(arr1, 5);
    cout << endl;
    print_rev_char_array(arr1, 5);
    cout << endl;

    print_char_array(arr2, 8);
    cout << endl;
    print_rev_char_array(arr2, 8);
    cout << endl;

    print_char_array(arr3, 1);
    cout << endl;
    print_rev_char_array(arr3, 1);
    cout << endl;
    return 0;
}