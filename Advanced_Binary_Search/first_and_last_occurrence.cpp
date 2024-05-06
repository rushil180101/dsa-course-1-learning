#include <bits/stdc++.h>
using namespace std;

int* get_min_max_idx_binary_search(int arr[], int s, int e, int t)
{
    int min_idx = e, max_idx = s;
    bool is_element_present = false;

    int *idx = new int [2];
    idx[0] = -1;
    idx[1] = -1;

    while (s <= e)
    {
        int m = (s + e) / 2;
        if (arr[m] == t)
        {
            is_element_present = true;
            int *l_half = get_min_max_idx_binary_search(arr, s, m-1, t);
            int *r_half = get_min_max_idx_binary_search(arr, m+1, e, t);

            int l_half_min_idx = l_half[0];
            int r_half_max_idx = r_half[1];

            min_idx = (l_half_min_idx == -1) ? m : min(l_half_min_idx, m);
            max_idx = (r_half_max_idx == -1) ? m : max(r_half_max_idx, m);

            idx[0] = min_idx;
            idx[1] = max_idx;
            return idx;
        }
        if (arr[m] > t)
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return idx;
}

void display_idx(int *arr)
{
    cout << "[" << arr[0] << ", " << arr[1] << "]" << endl;
}

// Approach-2 : Get first and last index separately
int get_index(vector<int> v, int t, bool get_first=true)
{
    int idx = -1;
    int s = 0, e = v.size() - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (v[m] == t)
        {
            idx = m;

            // LHS search (get first occurrence)
            if (get_first)
            {
                e = m - 1;
            }
            else // RHS search (get last occurrence)
            {
                s = m + 1;
            }
        }
        else if (v[m] < t)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return idx;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int arr1[7] = {1, 2, 3, 3, 3, 4, 5};
    int arr2[15] = {1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5};
    int arr3[6] = {10, 20, 30, 40, 40, 40};

    int *r1 = get_min_max_idx_binary_search(arr1, 0, 6, 1);
    int *r2 = get_min_max_idx_binary_search(arr1, 0, 6, 2);
    int *r3 = get_min_max_idx_binary_search(arr1, 0, 6, 3);
    int *r4 = get_min_max_idx_binary_search(arr1, 0, 6, 4);
    int *r5 = get_min_max_idx_binary_search(arr1, 0, 6, 5);
    int *r6 = get_min_max_idx_binary_search(arr1, 0, 6, 6);
    display_idx(r1); // 0, 0
    display_idx(r2); // 1, 1
    display_idx(r3); // 2, 4
    display_idx(r4); // 5, 5
    display_idx(r5); // 6, 6
    display_idx(r6); // -1, -1
    cout << "\n--------------------\n";

    display_idx(get_min_max_idx_binary_search(arr2, 0, 14, 1)); // 0, 0
    display_idx(get_min_max_idx_binary_search(arr2, 0, 14, 2)); // 1, 3
    display_idx(get_min_max_idx_binary_search(arr2, 0, 14, 3)); // 4, 6
    display_idx(get_min_max_idx_binary_search(arr2, 0, 14, 4)); // 7, 7
    display_idx(get_min_max_idx_binary_search(arr2, 0, 14, 5)); // 8, 14
    display_idx(get_min_max_idx_binary_search(arr2, 0, 14, 6)); // -1, -1
    cout << "\n--------------------\n";

    display_idx(get_min_max_idx_binary_search(arr3, 0, 5, 10)); // 0, 0
    display_idx(get_min_max_idx_binary_search(arr3, 0, 5, 20)); // 1, 1
    display_idx(get_min_max_idx_binary_search(arr3, 0, 5, 30)); // 2, 2
    display_idx(get_min_max_idx_binary_search(arr3, 0, 5, 40)); // 3, 5
    display_idx(get_min_max_idx_binary_search(arr3, 0, 5, 50)); // -1, -1
    cout << "\n--------------------\n";

    int arr4[13] = {1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 4, 5, 5};
    display_idx(get_min_max_idx_binary_search(arr4, 0, 12, 1)); // 0, 2
    display_idx(get_min_max_idx_binary_search(arr4, 0, 12, 2)); // 3, 7
    display_idx(get_min_max_idx_binary_search(arr4, 0, 12, 3)); // 8, 9
    display_idx(get_min_max_idx_binary_search(arr4, 0, 12, 4)); // 10, 10
    display_idx(get_min_max_idx_binary_search(arr4, 0, 12, 5)); // 11, 12
    display_idx(get_min_max_idx_binary_search(arr4, 0, 12, 6)); // -1, -1
    cout << "\n--------------------\n";

    vector<int> v1 = {1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 4, 5, 5};
    cout << "5 - " << get_index(v1, 5, true) << ", " << get_index(v1, 5, false) << endl; // 11, 12
    cout << "1 - " << get_index(v1, 1, true) << ", " << get_index(v1, 1, false) << endl; // 0, 2
    cout << "2 - " << get_index(v1, 2, true) << ", " << get_index(v1, 2, false) << endl; // 3, 7
    cout << "3 - " << get_index(v1, 3, true) << ", " << get_index(v1, 3, false) << endl; // 8, 9
    cout << "7 - " << get_index(v1, 7, true) << ", " << get_index(v1, 7, false) << endl; // -1, -1
    cout << "4 - " << get_index(v1, 4, true) << ", " << get_index(v1, 4, false) << endl; // 10, 10
    cout << endl;

    return 0;
}