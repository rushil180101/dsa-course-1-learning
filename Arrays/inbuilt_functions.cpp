#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*
1. strlen - actual input string length
2. strcmp - compare two strings
3. strcpy - copy one string to another
4. strncpy - copy first n chars from one string to another
5. strcat - concatenate one string at the end of another
*/

int custom_strcmp(char str1[], char str2[])
{
    if (strlen(str1) != strlen(str2))
    {
        return 0;
    }
    for (int i=0; i<strlen(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    char str1[100];
    cin.getline(str1, 100);
    int len = strlen(str1);
    cout << "Length of '" << str1 << "' = " << len << endl;

    char str2[50];
    cin.getline(str2, 100);
    int result = strcmp(str1, str2);
    string output = (result == 0) ? "Equal" : "Not equal";
    cout << output << endl;

    int is_equal = custom_strcmp(str1, str2);
    cout << "Custom strcmp - ";
    if (is_equal)
    {
        cout << "Equal";
    }
    else
    {
        cout << "Not equal";
    }
    cout << endl;

    char str3[100], str4[100] = "cplusplus";
    cin.getline(str3, 100);
    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    strcpy(str4, str3);
    cout << "str4 = " << str4 << endl;

    char str5[100], str6[100] = "str6 value";
    cin.getline(str5, 100);
    cout << "str5 = " << str5 << endl;
    cout << "str6 = " << str6 << endl;
    strncpy(str6, str5, 5);
    cout << "str6 = " << str6 << endl;

    cout << "After string concatenation" << endl;
    strcat(str5, " hello");
    cout << "str5 = " << str5 << endl;

    return 0;
}
