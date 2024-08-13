#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<T> get_k_smallest_elements_v1(vector<T> v, int k)
{
    // Using max heap : time complexity = O(n log k)
    int n = v.size();
    vector<T> k_smallest_elements;
    priority_queue<T> max_pq;
    for (int i=0; i<k; i++)
    {
        max_pq.push(v[i]);
    }
    for (int i=k; i<n; i++)
    {
        if (v[i]<max_pq.top())
        {
            max_pq.pop();
            max_pq.push(v[i]);
        }
    }
    for (int i=0; i<k; i++)
    {
        k_smallest_elements.push_back(max_pq.top());
        max_pq.pop();
    }
    return k_smallest_elements;
}

template <class T>
vector<T> get_k_smallest_elements_min_pq(vector<T> v, int k)
{
    int n = v.size();
    vector<T> k_smallest_elements;
    priority_queue<T, vector<T>, greater<T>> min_pq;
    for (int i=0; i<n; i++)
    {
        min_pq.push(v[i]);
    }
    for (int i=0; i<k; i++)
    {
        k_smallest_elements.push_back(min_pq.top());
        min_pq.pop();
    }
    return k_smallest_elements;
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

    vector<int> v1 = {8, 5, 12, 10, 0, 1, 6, 9};
    vector<int> ksv1 = get_k_smallest_elements_v1(v1, 4);
    display_vector(ksv1);

    vector<int> v2 = {3, 8, 5, 7, 6, 2, 1, 4};
    vector<int> ksv2 = get_k_smallest_elements_v1(v2, 3);
    display_vector(ksv2);

    vector<int> v3 = {5, 6, 9, 12, 3, 13, 2};
    vector<int> ksv3 = get_k_smallest_elements_v1(v3, 3);
    display_vector(ksv3);

    cout << "\n---------------------------------\n";

    vector<float> v4 = {8.69, 3.45, 1.07, 8.45, 5.641, 237.48, 1.674, 6.4, 4.7};
    vector<float> ksv4 = get_k_smallest_elements_min_pq(v4, 3);
    display_vector(ksv4);
    cout << "\n\n";

    vector<int> v5 = {1, 2, 3, 5, 4};
    vector<int> ksv5 = get_k_smallest_elements_min_pq(v5, 3);
    display_vector(ksv5);
    cout << "\n\n";

    vector<int> v6 = {5, 6, 9, 12, 3, 13, 2};
    vector<int> ksv6 = get_k_smallest_elements_min_pq(v6, 3);
    display_vector(ksv6);
    cout << "\n\n";

    vector<int> v7 = {8, 5, 12, 10, 0, 1, 6, 9};
    vector<int> ksv7 = get_k_smallest_elements_min_pq(v7, 4);
    display_vector(ksv7);
    cout << "\n\n";

    return 0;
}