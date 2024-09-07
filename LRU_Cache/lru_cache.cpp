#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    map<int, int> kv_store;
    list<int> cache;
    int capacity;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->cache.clear();
        this->kv_store.clear();
    }

    int get(int key)
    {
        if (this->kv_store.find(key)==this->kv_store.end())
        {
            cout << "-1" << endl;
            return -1;
        }
        // Bring latest accessed element to front of cache
        this->cache.remove(key);
        this->cache.push_front(key);

        cout << this->kv_store[key] << endl;
        return this->kv_store[key];
    }

    void put(int key, int value)
    {
        if (this->kv_store.find(key)==this->kv_store.end())
        {
            // Key not found
            if (this->cache.size()==this->capacity)
            {
                // cache full
                // Remove last element
                int last = this->cache.back();
                this->cache.pop_back();
                this->kv_store.erase(last);
            }
            // Insert new element
            this->kv_store[key] = value;
            this->cache.push_front(key);
        }
        else
        {
            // Key found, update value
            this->kv_store[key] = value;
            // Bring latest accessed element to front of cache
            this->cache.remove(key);
            this->cache.push_front(key);
        }
        cout << "null" << endl;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    LRUCache l1(2);
    l1.put(1, 1);
    l1.put(2, 2);
    l1.get(1);
    l1.put(3, 3);
    l1.get(2);
    l1.put(4, 4);
    l1.get(1);
    l1.get(3);
    l1.get(4);

    return 0;
}