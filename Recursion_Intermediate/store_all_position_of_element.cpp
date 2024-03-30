#include <bits/stdc++.h>
using namespace std;

vector<int> store_all_idx_position_of_element(int arr[], int n, int e, int i, vector<int> v)
{
    if (i == n)
    {
        return v;
    }
    if (arr[i] == e)
    {
        v.push_back(i);
    }
    return store_all_idx_position_of_element(arr, n, e, i+1, v);
}

void display(vector<int> v)
{
    for (int i=0; i<v.size(); i++)
    {
        cout << v.at(i) << "  ";
    }
    cout << endl;
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

    vector<int> v1, v2;
    v2 = store_all_idx_position_of_element(a1, 11, 1, 0, v1);
    display(v2); // 0 3 4 5

    v1.clear();
    v2.clear();
    v2 = store_all_idx_position_of_element(a1, 11, 2, 0, v1);
    display(v2); // 1 7 8 9 10

    v1.clear();
    v2.clear();
    v2 = store_all_idx_position_of_element(a1, 11, 3, 0, v1);
    display(v2); // 2 6

    v1.clear();
    v2.clear();
    v2 = store_all_idx_position_of_element(a1, 11, 5, 0, v1);
    display(v2); // no output

    v1.clear();
    v2.clear();
    v2 = store_all_idx_position_of_element(a2, 5, 5, 0, v1);
    display(v2); // 1 2 4

    v1.clear();
    v2.clear();
    v2 = store_all_idx_position_of_element(a2, 5, 6, 0, v1);
    display(v2); // 0 3

    v1.clear();
    v2.clear();
    v2 = store_all_idx_position_of_element(a3, 6, 7, 0, v1);
    display(v2); // 4

    v1.clear();
    v2.clear();
    v2 = store_all_idx_position_of_element(a3, 6, 10, 0, v1);
    display(v2); // no output

    return 0;
}