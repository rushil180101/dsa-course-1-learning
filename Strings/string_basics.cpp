#include <bits/stdc++.h>
using namespace std;

template <class T>
void display_2d_array(T *a[], int x, int y)
{
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            cout << setw(4) << T(*(a[i]) + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    string s1 = "abc";
    cout << s1 << endl;

    // Storing 2d arrays
    char a[5][5] = {
        {'a', 'b', 'c', 'd', 'e'},
        {'f', 'g', 'h', 'i', 'j'},
        {'k', 'l', 'm', 'n', 'o'},
        {'k', 'l', 'm', 'n', 'o'},
        {'p', 'q', 'r', 's', 't'}
    };
    char *p[5];
    for (int i=0; i<5; i++)
    {
        p[i] = a[i];
    }
    display_2d_array(p, 5, 5);

    char b[5][5] = {
        {'a', 'b', 'c', 'd', '\0'},
        {'f', 'g', 'h', 'i', '\0'},
        {'k', 'l', 'm', 'n', '\0'},
        {'k', 'l', 'm', 'n', '\0'},
        {'p', 'q', 'r', 's', '\0'}
    };
    for (int i=0; i<5; i++)
    {
        cout << b[i] << endl;
    }
    cout << endl;

    // Alternative
    vector<string> strv1;
    strv1.push_back("abcd");
    strv1.push_back("efgh");
    strv1.push_back("ijkl");
    strv1.push_back("mnop");
    strv1.push_back("qrstuvwxyz");
    cout << "Vector - 1" << endl;
    for (vector<string>::iterator iter = strv1.begin(); iter != strv1.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << endl;
    string temp;
    cout << "Vector - 2" << endl;
    for (vector<string>::iterator iter = strv1.begin(); iter != strv1.end(); iter++)
    {
        temp = *iter;
        for (int i=0; i<temp.length(); i++)
        {
            cout << setw(4) << temp[i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Get space seperated line input into string
    string s2;
    getline(cin, s2);
    cout << s2 << endl;

    // String concatenation
    string s3 = s2 + "testing";
    cout << s3 << endl;

    // Substr
    string sub1 = s3.substr(2);
    string sub2 = s3.substr(3, 5);
    cout << "Substrings" << endl;
    cout << sub1 << endl;
    cout << sub2 << endl;

    // Convert int to string using to_string()
    int d = 156;
    string s4 = to_string(d);
    cout << d << ", " << s4 << endl;

    return 0;
}
