#include <bits/stdc++.h>
using namespace std;

template <class T>
class BTNode
{
public:
    T data;
    BTNode *left, *right;

    BTNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // Recursive destructor
    ~BTNode()
    {
        delete this->left;
        delete this->right;
    }
};

template <class T>
BTNode<T>* take_binary_tree_input_recursive()
{
    T root_data;
    cin >> root_data;

    if (root_data == -1)
        return NULL;

    BTNode<T> *root = new BTNode<T>(root_data);

    // Take input left subtree
    root->left = take_binary_tree_input_recursive<T>();

    // Take input right subtree
    root->right = take_binary_tree_input_recursive<T>();

    return root;
}

template <class T>
void print_binary_tree_recursive(BTNode<T> *root)
{
    if (root == NULL)
        return;

    // Print data
    cout << left << setw(5) << root->data << ": ";
    if (root->left)
        cout << "L=" << left << setw(5) << root->left->data << " ";
    if (root->right)
        cout << "R=" << left << setw(5) << root->right->data << " ";
    cout << endl;

    // Print left substree
    print_binary_tree_recursive(root->left);

    // Print right substree
    print_binary_tree_recursive(root->right);
}

int main() 
{
    // ########################## //
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    BTNode<int> *root = new BTNode<int>(1);
    BTNode<int> *n2 = new BTNode<int>(2);
    BTNode<int> *n3 = new BTNode<int>(3);
    BTNode<int> *n4 = new BTNode<int>(4);
    BTNode<int> *n5 = new BTNode<int>(5);
    BTNode<int> *n6 = new BTNode<int>(6);
    BTNode<int> *n7 = new BTNode<int>(7);

    root->left = n2;
    root->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    print_binary_tree_recursive(root);

    delete root;
    cout << "\n\n";

    // Take tree input
    // Test input 1 = 2 3 8 -1 -1 5 9 -1 -1 -1 7 1 -1 -1 6 -1 4 -1 -1
    // Test input 2 = 15 21 8 11 -1 -1 2 -1 -1 7 4 -1 -1 1 -1 -1 6 3 37 -1 -1 19 -1 -1 20 5 -1 -1 10 -1 -1

    cout << "Enter tree : ";
    BTNode<int> *root_tree1 = take_binary_tree_input_recursive<int>();
    cout << "Enter tree : ";
    BTNode<int> *root_tree2 = take_binary_tree_input_recursive<int>();

    cout << "Tree 1\n";
    print_binary_tree_recursive(root_tree1);

    cout << "\n\n";
    cout << "Tree 2\n";
    print_binary_tree_recursive(root_tree2); 

    return 0;
}