#include <bits/stdc++.h>
using namespace std;

void remove_consecutive_duplicates(char arr[], char prev='\0')
{
    if (arr[0] == '\0')
    {
        return;
    }
    if (arr[0] == prev)
    {
        for (int i=0; arr[i]!='\0'; i++)
        {
            arr[i] = arr[i+1];
        }
        remove_consecutive_duplicates(arr, prev);
    }
    else
    {
        remove_consecutive_duplicates(arr + 1, arr[0]);
    }
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    char a1[] = "aabbbcda";
    cout << a1 << endl;
    remove_consecutive_duplicates(a1);
    cout << a1 << endl; // abcda

    char a2[] = "hhhhhhhhhhhh";
    cout << a2 << endl;
    remove_consecutive_duplicates(a2);
    cout << a2 << endl; // h

    char a3[] = "ppppqqrrrrrrrrs";
    cout << a3 << endl;
    remove_consecutive_duplicates(a3);
    cout << a3 << endl; // pqrs

    char a4[] = "efghh";
    cout << a4 << endl;
    remove_consecutive_duplicates(a4);
    cout << a4 << endl; // efgh

    return 0;
}