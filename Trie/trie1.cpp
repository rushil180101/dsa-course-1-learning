#include <bits/stdc++.h>
using namespace std;

template <class T>
class TrieNode
{
public:
    bool is_terminal;
    TrieNode<T>* children[26];

    TrieNode()
    {
        this->is_terminal = false;
        for (int i=0; i<26; i++)
        {
            this->children[i] = NULL;
        }
    }
};

template <class T>
class Trie
{
public:
    TrieNode<T> *root;

    Trie()
    {
        this->root = NULL;
    }

    void add (string word)
    {
        if (this->root==NULL)
        {
            this->root = new TrieNode<T>();
        }

        TrieNode<T> *temp = this->root;
        for (int i=0; i<word.length(); i++)
        {
            int idx = word[i] - 'A';
            if (temp->children[idx]==NULL)
            {
                temp->children[idx] = new TrieNode<T>();
            }
            temp = temp->children[idx];
        }
        temp->is_terminal = true;
    }

    bool search(string word)
    {
        if (this->root==NULL)
        {
            return false;
        }
        TrieNode<T> *temp = this->root;
        for (int i=0; i<word.length(); i++)
        {
            int idx = word[i] - 'A';
            if (temp->children[idx]==NULL)
                return false;

            temp = temp->children[idx];
        }
        return temp->is_terminal;

    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<string> v = {
        "ARE",
        "AS",
        "DO",
        "DOT",
        "NEW",
        "NEWS",
        "NO",
        "NOT"
    };
    Trie<char> trie1;
    for (int i=0; i<v.size(); i++)
    {
        trie1.add(v[i]);
    }

    for (int i=0; i<v.size(); i++)
    {
        cout << trie1.search(v[i]) << endl;
    }
    cout << "\n\n";
    cout << trie1.search("ABCD") << endl;
    cout << trie1.search("PQRS") << endl;
    cout << trie1.search("AR") << endl;
    cout << trie1.search("NOTES") << endl;

    return 0;
}