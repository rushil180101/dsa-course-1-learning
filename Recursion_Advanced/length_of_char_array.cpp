#include <bits/stdc++.h>
using namespace std;

int length_of_char_array(char arr[])
{
    if (arr[0] == '\0')
    {
        return 0;
    }
    return 1 + length_of_char_array(arr + 1);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    char arr1[] = "abcdefgh";
    char arr2[] = "123456789012345";
    char arr3[] = "x";
    char arr4[] = "";

    cout << length_of_char_array(arr1) << endl; // 8
    cout << length_of_char_array(arr2) << endl; // 15
    cout << length_of_char_array(arr3) << endl; // 1
    cout << length_of_char_array(arr4) << endl; // 0

    return 0;
}