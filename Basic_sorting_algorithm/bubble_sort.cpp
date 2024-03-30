#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    cout << endl << "Bubble sort" << endl;
    cout << endl << "Array before sorting" << endl;
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // If n elements, perform n-1 rounds
    for (int round=1; round<=n-1; round++)
    {
        for (int i=0; i<n-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
            }
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

void optimized_bubble_sort(int arr[], int n)
{
    cout << endl << "Optimized Bubble sort" << endl;
    cout << endl << "Array before sorting" << endl;
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // If no swapping occurs, then array is already sorted
    bool swapped;
    for (int round=1; round<=n-1; round++)
    {
        swapped = false;
        for (int i=0; i<n-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
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

    bubble_sort(arr1, 7);
    bubble_sort(arr2, 10);

    int arr3[5] = {5, 4, 3, 2, 1};
    int arr4[5] = {1, 2, 3, 4, 5};
    optimized_bubble_sort(arr3, 5);
    optimized_bubble_sort(arr4, 5);

    return 0;
}
