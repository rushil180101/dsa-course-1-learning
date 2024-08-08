#include <bits/stdc++.h>
using namespace std;

template <class T>
class KVEntry
{
public:
    string key;
    T value;
    KVEntry<T> *next;

    KVEntry(string key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~KVEntry()
    {
        delete this->next;
    }
};

template <class T>
class HashMap
{
public:
    int kv_pairs;
    int bucket_array_size;
    KVEntry<T> **bucket_array;

    HashMap(int bucket_array_size=10)
    {
        this->bucket_array_size = bucket_array_size;
        this->bucket_array = new KVEntry<T>*[bucket_array_size];
        this->kv_pairs = 0;
        for (int i=0; i<bucket_array_size; i++)
        {
            this->bucket_array[i] = NULL;
        }
    }
    ~HashMap()
    {
        for (int i=0; i<this->bucket_array_size; i++)
        {
            delete this->bucket_array[i];
        }
        delete []this->bucket_array;
    }

private:
    int hash_function(string s)
    {
        int p = 31; // prime number
        // Calculate hash code
        int x = 0;
        long long int hash_code = 0;
        for (int i=s.length()-1; i>=0; i--)
        {
            hash_code += int(s[i]) * pow(p, x);
            x++;
        }
        // Apply compression
        int bucket_array_idx = hash_code % this->bucket_array_size;
        return bucket_array_idx;
    }

public:
    // Size of hashmap
    int size()
    {
        return this->kv_pairs;
    }

    // Set key-value pair
    void set_kv(string key, T value)
    {
        int bucket_array_idx = this->hash_function(key);
        if (this->bucket_array[bucket_array_idx])
        {
            KVEntry<T> *temp = this->bucket_array[bucket_array_idx];
            while (temp && temp->next && temp->key!=key)
            {
                temp = temp->next;
            }
            if (temp->key==key)
            {
                temp->value = value;
                return;
            }
            temp->next = new KVEntry<T>(key, value);
            this->kv_pairs++;
        }
        else
        {
            this->bucket_array[bucket_array_idx] = new KVEntry<T>(key, value);
            this->kv_pairs++;
        }
    }

    // Get value from key-value pair
    T get_kv(string key)
    {
        int bucket_array_idx = this->hash_function(key);
        if (this->bucket_array[bucket_array_idx])
        {
            KVEntry<T> *temp = this->bucket_array[bucket_array_idx];
            while (temp)
            {
                if (temp->key==key)
                    return temp->value;
                temp = temp->next;
            }
        }
        return 0;
    }

    // Remove key-value pair
    T remove_kv(string key)
    {
        int bucket_array_idx = this->hash_function(key);
        if (this->bucket_array[bucket_array_idx])
        {
            KVEntry<T> *temp = this->bucket_array[bucket_array_idx];
            if (temp->key==key)
            {
                this->bucket_array[bucket_array_idx] = temp->next;
                temp->next = NULL;
                T value = temp->value;
                delete temp;
                this->kv_pairs--;
                return value;
            }
            while (temp && temp->next)
            {
                if (temp->next->key==key)
                {
                    T value = temp->next->value;
                    KVEntry<T> *isolated = temp->next;
                    temp->next = isolated->next;
                    isolated->next = NULL;
                    delete isolated;
                    this->kv_pairs--;
                    return value;
                }
                temp = temp->next;
            }
        }
        return 0;
    }

    // Display hashmap
    void display()
    {
        for (int i=0; i<this->bucket_array_size; i++)
        {
            KVEntry<T> *node = this->bucket_array[i];
            cout << setw(3) << i << ": ";
            while (node)
            {
                cout << "(" << node->key << "," << node->value << ")-->";
                node = node->next;
            }
            cout << "NULL\n";       
        }
        cout << endl;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    HashMap<int> hmap1;
    hmap1.set_kv("abc", 5);
    hmap1.set_kv("def", 6);
    hmap1.set_kv("ghi", 7);
    hmap1.set_kv("jkl", 8);
    hmap1.set_kv("mno", 1);
    hmap1.set_kv("pqr", 4);
    hmap1.set_kv("st", 3);
    hmap1.set_kv("uvwx", 9);
    hmap1.set_kv("yz", 2);

    hmap1.display();
    cout << hmap1.size() << endl;
    string key;
    key = "ghi";
    cout << key << " = " << hmap1.get_kv(key) << endl;
    key = "mno";
    cout << key << " = " << hmap1.get_kv(key) << endl;
    key = "uvwx";
    cout << key << " = " << hmap1.get_kv(key) << endl;
    key = "hello";
    cout << key << " = " << hmap1.get_kv(key) << endl;

    hmap1.set_kv("mno", 55);
    hmap1.set_kv("yz", 65);
    hmap1.set_kv("ghi", 75);
    hmap1.display();
    cout << hmap1.size() << endl;
    
    int a = hmap1.remove_kv("pqr");
    int b = hmap1.remove_kv("st");
    int c = hmap1.remove_kv("def");
    hmap1.display();
    cout << hmap1.size() << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}