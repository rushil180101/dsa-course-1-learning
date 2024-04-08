#include <bits/stdc++.h>
using namespace std;

void replace_char(char arr[], char to_replace, char replacement)
{
    if (arr[0] == '\0')
    {
        return;
    }
    if (arr[0] == to_replace)
    {
        arr[0] = replacement;
    }
    replace_char(arr + 1, to_replace, replacement);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    char arr1[] = "abcdaefghapq";
    char arr2[] = "hhhhhhh";
    char arr3[] = "wxyzefgh";

    cout << arr1 << endl;
    replace_char(arr1, 'a', '1');
    cout << arr1 << endl;

    cout << arr2 << endl;
    replace_char(arr2, 'h', 'j');
    cout << arr2 << endl;

    cout << arr3 << endl;
    replace_char(arr3, 'm', 'p');
    cout << arr3 << endl;
    return 0;
}