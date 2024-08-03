#include <bits/stdc++.h>
using namespace std;

template <class T>
class BSTNode
{
public:
    T data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // Recusrive destructor
    ~BSTNode()
    {
        delete this->left;
        delete this->right;
    }
};


template <class T>
class BST
{
    BSTNode<T> *root;

    int get_nodes_count(BSTNode<T> *node)
    {
        if (node==NULL)
            return 0;
        
        return 1 + get_nodes_count(node->left) + get_nodes_count(node->right);
    }

    BSTNode<T>* delete_data_helper(BSTNode<T> *node, T data, string flag="right")
    {
        if (node==NULL)
            return NULL;
        
        // Reached node
        if (node->data==data)
        {
            // Case 1 - No left and right subtree
            if (node->left==NULL && node->right==NULL)
            {
                delete node;
                return NULL;
            }
            // Case 2 - Light subtree exists
            else if (node->left && node->right==NULL)
            {
                BSTNode<T> *new_node = node->left;
                // Break connection
                node->left = NULL;
                delete node;
                return new_node;
            }
            // Case 3 - Right subtree exists
            else if (node->left==NULL && node->right)
            {
                BSTNode<T> *new_node = node->right;
                // Break connection
                node->right = NULL;
                delete node;
                return new_node;
            }
            // Case 4 - Both left and right subtree exist
            else
            {
                // Break case 4 into case 1, 2 or 3
                // Replace left max or right min with root
                // And then delete that left max or right min from tree

                // Here, taking left max - rightmost (max) element in left subtree
                // or right min - leftmost (min) element in right subtree
                // based on flag

                if (flag=="left")
                {
                    // Get max rightmost element from left subtree
                    BSTNode<T> *rightmost = node->left;
                    while (rightmost->right)
                    {
                        rightmost = rightmost->right;
                    }

                    // Replace
                    node->data = rightmost->data;

                    // Case 4 converted into smaller problem (Case 1, 2 or 3)
                    node->left = delete_data_helper(
                        node->left,
                        rightmost->data,
                        flag
                    );
                }
                else
                {
                    // Get min leftmost element from right subtree
                    BSTNode<T> *leftmost = node->right;
                    while (leftmost->left)
                    {
                        leftmost = leftmost->left;
                    }

                    // Replace
                    node->data = leftmost->data;

                    // Case 4 converted into smaller problem (Case 1, 2 or 3)
                    node->right = delete_data_helper(
                        node->right,
                        leftmost->data,
                        flag
                    );
                }
                return node;
            }
        }

        // Not yet reached node
        if (data<node->data)
        {
            // Element present in left subtree
            node->left = delete_data_helper(
                node->left,
                data,
                flag
            );
        }
        else
        {
            // Element present in right subtree
            node->right = delete_data_helper(
                node->right,
                data,
                flag
            );
        }
        return node;
    }

public:
    // Constructor
    BST()
    {
        this->root = NULL;
    }
    // Recusrive destructor
    ~BST()
    {
        delete this->root;
    }

    // Helper functions

    void insert_data(T data)
    {
        if (this->root==NULL)
        {
            BSTNode<T> *node = new BSTNode<T>(data);
            this->root = node;
        }
        else
        {
            BSTNode<T> *temp = this->root;
            while (temp)
            {
                if (temp->data>data)
                {
                    if (temp->left==NULL)
                    {
                        temp->left = new BSTNode<T>(data);
                        break;
                    }
                    temp = temp->left;
                }
                else
                {
                    if (temp->right==NULL)
                    {
                        temp->right = new BSTNode<T>(data);
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }

    void delete_data(T data)
    {
        this->root = delete_data_helper(this->root, data);
    }

    bool has_data(T data)
    {
        if (this->root==NULL)
            return false;
        BSTNode<T> *temp = this->root;
        while (temp)
        {
            if (temp->data==data)
                return true;
            
            if (temp->data>data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    void print_level_wise()
    {
        if (this->root==NULL)
            return;

        // Push root node
        queue<BSTNode<T>*> q;
        q.push(this->root);
        q.push(NULL); // NULL is used to differentiate levels

        while (!q.empty())
        {
                // Pop node from q
                BSTNode<T> *current_node = q.front();
                q.pop();

                if (current_node==NULL)
                {
                    cout << endl; // Prev level is finished so move to next line
                    if (!q.empty())
                        q.push(NULL);
                    continue;
                }

                // Print node
                cout << "[" << left << setw(4) << current_node->data << ": ";

                // Left child
                if (current_node->left)
                {
                    cout << "L=" << left << setw(4) << current_node->left->data;
                    q.push(current_node->left);
                }
                // Right child
                if (current_node->right)
                {
                    cout << "R=" << left << setw(4) << current_node->right->data;
                    q.push(current_node->right);
                }
                cout << "], ";
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

    // BST<int> bst1;
    // bst1.insert_data(4);
    // bst1.insert_data(2);
    // bst1.insert_data(6);
    // bst1.insert_data(1);
    // bst1.insert_data(3);
    // bst1.insert_data(5);
    // bst1.insert_data(7);

    // bst1.print_level_wise();
    // cout << bst1.has_data(3) << endl; // 1
    // cout << bst1.has_data(9) << endl; // 0
    // cout << "\n";

    // BST<int> bst2;
    // bst2.insert_data(10);
    // bst2.insert_data(5);
    // bst2.insert_data(20);
    // bst2.insert_data(7);
    // bst2.insert_data(3);
    // bst2.insert_data(15);
    // bst2.print_level_wise();
    // cout << bst2.has_data(3) << endl; // 1
    // cout << bst2.has_data(20) << endl; // 1
    // cout << bst2.has_data(16) << endl; // 0
    // cout << bst2.has_data(2) << endl; // 0
    // cout << "\n";

    cout << "\n-------------------------------------\n";

    BST<int> bst3;
    bst3.insert_data(10);
    bst3.insert_data(5);
    bst3.insert_data(20);
    bst3.insert_data(7);
    bst3.insert_data(3);
    bst3.insert_data(15);
    bst3.delete_data(15);
    bst3.print_level_wise();

    BST<int> bst4;
    bst4.insert_data(10);
    bst4.insert_data(5);
    bst4.insert_data(20);
    bst4.insert_data(7);
    bst4.insert_data(3);
    bst4.insert_data(15);
    bst4.delete_data(100);
    bst4.print_level_wise();

    BST<int> bst5;
    bst5.insert_data(10);
    bst5.insert_data(5);
    bst5.insert_data(20);
    bst5.insert_data(7);
    bst5.insert_data(3);
    bst5.insert_data(15);
    bst5.delete_data(5);
    bst5.print_level_wise();

    BST<int> bst6;
    bst6.insert_data(10);
    bst6.insert_data(5);
    bst6.insert_data(20);
    bst6.insert_data(7);
    bst6.insert_data(3);
    bst6.insert_data(15);
    bst6.delete_data(7);
    bst6.print_level_wise();

    BST<int> bst7;
    bst7.insert_data(10);
    bst7.insert_data(5);
    bst7.insert_data(20);
    bst7.insert_data(7);
    bst7.insert_data(3);
    bst7.insert_data(15);
    bst7.delete_data(10);
    bst7.print_level_wise();
    bst7.delete_data(5);
    bst7.print_level_wise();
    bst7.delete_data(7);
    bst7.print_level_wise();
    bst7.delete_data(20);
    bst7.print_level_wise();

    return 0;
}