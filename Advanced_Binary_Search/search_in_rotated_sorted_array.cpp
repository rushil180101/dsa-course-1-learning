#include <bits/stdc++.h>
using namespace std;

int get_idx_from_rotated_sorted_vector(vector<int> v, int element)
{
    // Plot graph for rotated sorted array
    // X-axis = index
    // Y-axis = value at given index
    int s = 0, e = v.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] == element)
        {
            return mid;
        }
        // Case 1
        if (v[mid] >= v[s])
        {
            if ((element >= v[s]) && (element <= v[mid]))
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        // Case 2 (v[mid] < v[e])
        else
        {
            if ((element >= v[mid]) && (element <= v[e]))
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;    
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<int> v1 = {4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
    cout << get_idx_from_rotated_sorted_vector(v1, 2) << endl; // 8
    cout << get_idx_from_rotated_sorted_vector(v1, 7) << endl; // 3
    cout << get_idx_from_rotated_sorted_vector(v1, 4) << endl; // 0
    cout << get_idx_from_rotated_sorted_vector(v1, 10) << endl; // 6
    cout << "\n----------\n";

    vector<int> v2 = {12, 13, 14, 1, 2, 3, 7, 8, 10};
    cout << get_idx_from_rotated_sorted_vector(v2, 1) << endl; // 3
    cout << get_idx_from_rotated_sorted_vector(v2, 2) << endl; // 4
    cout << get_idx_from_rotated_sorted_vector(v2, 3) << endl; // 5
    cout << get_idx_from_rotated_sorted_vector(v2, 7) << endl; // 6
    cout << get_idx_from_rotated_sorted_vector(v2, 8) << endl; // 7
    cout << get_idx_from_rotated_sorted_vector(v2, 10) << endl; // 8
    cout << get_idx_from_rotated_sorted_vector(v2, 12) << endl; // 0
    cout << get_idx_from_rotated_sorted_vector(v2, 13) << endl; // 1
    cout << get_idx_from_rotated_sorted_vector(v2, 14) << endl; // 2
    cout << get_idx_from_rotated_sorted_vector(v2, 20) << endl; // -1

    return 0;
}