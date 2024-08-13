#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<T> get_sorted_vector(vector<T> k_sorted_vector, int k)
{
    int n = k_sorted_vector.size();
    vector<T> sorted_vector;
    priority_queue<T> max_pq;
    for (int i=0; i<k; i++)
    {
        max_pq.push(k_sorted_vector[i]);
    }
    for (int i=0; i<n; i++)
    {
        T max_element = max_pq.top();
        max_pq.pop();
        sorted_vector.push_back(max_element);
        if (i+k<n)
        {
            max_pq.push(k_sorted_vector[i+k]);
        }
    }
    return sorted_vector;
}

template <class T>
void display_vector(vector<T> v)
{
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int k1 = 2;
    vector<int> k_sorted_v1 = {10, 15, 6, 4, 5};
    vector<int> sorted_v1 = get_sorted_vector<int>(k_sorted_v1, k1);
    display_vector(sorted_v1);

    int k2 = 3;
    vector<int> k_sorted_v2 = {10, 12, 6, 7, 9};
    vector<int> sorted_v2 = get_sorted_vector<int>(k_sorted_v2, k2);
    display_vector(sorted_v2);

    return 0;
}