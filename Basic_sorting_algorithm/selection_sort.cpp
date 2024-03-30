#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    cout << endl << "Selection sort" << endl;
    cout << endl << "Array before sorting" << endl;
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int min_val = INT_MAX, min_idx = -1;
    for (int i=0; i<n-1; i++)
    {
        min_val = INT_MAX;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j] < min_val)
            {
                min_val = arr[j];
                min_idx = j;
            }
        }
        if (arr[i] > arr[min_idx])
        {
            swap(arr[i], arr[min_idx]);
        }
    }
    cout << endl << "Array after sorting" << endl;
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int arr1[7] = {7, 3, 5, 1, 2, 4, 6};
    int arr2[10] = {87, 26, 65, 68, 31, 65, 58, 10, 79, 100};

    selection_sort(arr1, 7);
    selection_sort(arr2, 10);

    return 0;
}
