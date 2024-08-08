#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    unordered_map<int, string> umap1;
    umap1[1] = "Name1";
    umap1[2] = "Name2";
    umap1[3] = "Name3";
    umap1[4] = "Name4";
    umap1[5] = "Name5";
    // Traverse unordered map using iterator
    for (
        unordered_map<int, string>::iterator it=umap1.begin();
        it!=umap1.end();
        it++
    )
    {
        pair<int, string> p = *it;
        cout << "key = " << p.first << ", value = " << p.second << endl;
    }
    cout << "\n\n";

    map<char, float> mapper1;
    mapper1['c'] = 25.17;
    mapper1['a'] = 25.15;
    mapper1['b'] = 25.16;
    mapper1['d'] = 28.15;
    mapper1['g'] = 15.15;
    mapper1['f'] = 20.15;
    mapper1['e'] = 25.95;
    for (
        map<char, float>::iterator it=mapper1.begin();
        it!=mapper1.end();
        it++
    )
    {
        cout << "key = " << it->first << ", value = " << it->second << endl;
    }
    cout << mapper1.size() << endl;
    mapper1.erase(mapper1.begin(), mapper1.end());
    cout << mapper1.size() << endl;
    cout << "\n\n";

    // Iterators for vector
    vector<int> v = {10, 2, 4, 3, 5};
    for (
        vector<int>::iterator it=v.begin();
        it!=v.end();
        it++
    )
    {
        cout << *it << " ";
    }
    cout << endl;
    // Use of 'auto' keyword
    for (auto it=v.begin(); it!=v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n\n";

    return 0;
}