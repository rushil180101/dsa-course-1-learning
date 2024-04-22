#include <bits/stdc++.h>
using namespace std;

int* merge_sorted_arrays(int *arr1, int l1, int *arr2, int l2)
{
    int *arr3 = new int [l1+l2];
    int i = 0, j = 0, k = 0;
    while (i < l1 && j < l2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < l1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < l2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    return arr3;
}

int* merge_sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return arr;
    }
    int m = (s + e) / 2;
    int l_half[m+1], r_half[e-m];
    for (int i=0; i<=m; i++)
    {
        l_half[i] = arr[i];
    }
    for (int i=0; i<e-m; i++)
    {
        r_half[i] = arr[m+1+i];
    }
    int *arr1 = merge_sort(l_half, s, m);
    int *arr2 = merge_sort(r_half, s, e-m-1);
    int *arr3 = merge_sorted_arrays(arr1, m+1, arr2, e-m);
    return arr3;
}

void display_arr(int *arr, int n)
{
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t1[14] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 1, 2};
    display_arr(t1, 14);
    int *t2 = merge_sort(t1, 0, 13);
    display_arr(t2, 14);
    cout << endl;

    int t3[9] = {81, 43, 26, 15, 97, 10, 62, 11, 23};
    display_arr(t3, 9);
    int *t4 = merge_sort(t3, 0, 8);
    display_arr(t4, 9);
    cout << endl;

    int t5[7] = {34, 83, 22, 10, 75, 51, -1};
    display_arr(t5, 7);
    int *t6 = merge_sort(t5, 0, 6);
    display_arr(t6, 7);
    cout << endl;

    int t7[10] = {100, 90, 80, 70, 50, 60, 40, 30, 10, 20};
    display_arr(t7, 10);
    int *t8 = merge_sort(t7, 0, 9);
    display_arr(t8, 10);
    cout << endl;

    return 0;
}