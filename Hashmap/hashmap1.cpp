#include <bits/stdc++.h>
using namespace std;


template <class T>
vector<T> remove_duplicates(vector<T> v)
{
    vector<T> unique_elements;
    unordered_map<T, bool> element_mapper;
    for (int i=0; i<v.size(); i++)
    {
        if (!element_mapper.count(v[i]))
        {
            element_mapper[v[i]] = true;
            unique_elements.push_back(v[i]);
        }
    }
    return unique_elements;
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

    unordered_map<string, int> umap1;

    // Insert elements
    pair<string, int> p1("abc", 1);
    umap1.insert(p1);

    umap1["def"] = 2;
    umap1["ghi"] = 3;

    // Access elements
    cout << umap1.at("ghi") << endl;
    cout << umap1.at("def") << endl;
    cout << umap1.at("abc") << endl;

    cout << umap1["abc"] << endl;
    cout << umap1["def"] << endl;
    cout << umap1["ghi"] << endl;

    // Accessing non existing elements using at() vs square brackets[]
    // cout << umap1.at("pqr") << endl; // <-- throws out_of_range error
    cout << umap1["pqr"] << endl; // <-- creates an entry with value = 0

    // Check presence of key using count() function
    cout << umap1.count("abc") << endl;
    cout << umap1.count("pqr") << endl;
    cout << umap1.count("lmn") << endl;

    // Update values
    umap1["abc"] = 45;

    // Get size of the map (total number of key-value pairs)
    cout << "Size = " << umap1.size() << endl;

    // Delete elemets from map
    umap1.erase("def");
    cout << "Size = " << umap1.size() << endl;

    cout << "\n--------------------\n";

    vector<int> v1 = {1, 2, 3, 2, 1, 5, 4, 1, 3};
    vector<float> v2 = {1.56, 2.38, 3.37, 1.56, 3.37, 2.38, 4.91};
    vector<char> v3 = {'a', 'b', 'c', 'd', 'c', 'b', 'a', 'e'};

    vector<int> uv1 = remove_duplicates(v1);
    vector<float> uv2 = remove_duplicates(v2);
    vector<char> uv3 = remove_duplicates(v3);

    display_vector(v1);
    display_vector(uv1);
    cout << "\n";

    display_vector(v2);
    display_vector(uv2);
    cout << "\n";

    display_vector(v3);
    display_vector(uv3);
    cout << "\n";

    return 0;
}