#include <bits/stdc++.h>
using namespace std;

int partition_array(int arr[], int s, int e)
{
    // This function rearranges the array with pivot at its correct index
    // and returns the pivot index

    int pivot = arr[e];
    int count = 0;
    for (int i=s; i<=e; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }
    swap(arr[count], arr[e]);
    int i = s, j = e;
    while (i < count && j > count)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return count;
}

int* quick_sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return arr;
    }
    int p = partition_array(arr, s, e);
    int l_half[p], r_half[e-p];
    for (int i=0; i<p; i++)
    {
        l_half[i] = arr[i];
    }
    for (int i=0; i<e-p; i++)
    {
        r_half[i] = arr[p+1+i];
    }
    int *arr1 = quick_sort(l_half, s, p-1);
    int *arr2 = quick_sort(r_half, s, e-p-1);
    int *arr3 = new int [e+1];
    for (int i=0; i<=e; i++)
    {
        if (i < p)
        {
            arr3[i] = arr1[i];
        }
        else if (i > p)
        {
            arr3[i] = arr2[i-p-1];
        }
        else
        {
            arr3[i] = arr[p];
        }
    }
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
    int a1[7] = {7, 6, 5, 4, 3, 1, 2};
    display_arr(a1, 7);
    int *a2 = quick_sort(a1, 0, 6);
    display_arr(a2, 7);
    cout << endl;

    int a3[14] = {14, 6, 10, 8, 12, 4, 2, 1, 3, 5, 13, 9, 11, 7};
    display_arr(a3, 14);
    int *a4 = quick_sort(a3, 0, 13);
    display_arr(a4, 14);
    cout << endl;

    int a5[8] = {23, -1, 11, 59, 68, 41, 2, 36};
    display_arr(a5, 8);
    int *a6 = quick_sort(a5, 0, 7);
    display_arr(a6, 8);
    cout << endl;

    int a7[10] = {-3, 0, -3, 0, -1, 15, 43, 2, 6, -2};
    display_arr(a7, 10);
    int *a8 = quick_sort(a7, 0, 9);
    display_arr(a8, 10);
    cout << endl;

    return 0;
}