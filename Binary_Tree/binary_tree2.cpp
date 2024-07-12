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
BTNode<T>* take_binary_tree_input_level_wise()
{
    T data;
    cin >> data;
    if (data == -1)
        return NULL;
    
    queue<BTNode<T>*> q;
    BTNode<T> *root = new BTNode<T>(data);
    q.push(root);

    while (!q.empty())
    {
        BTNode<T> *current_node = q.front();
        q.pop();

        T left_data, right_data;
        cin >> left_data >> right_data;

        if (left_data != -1)
        {
            BTNode<T> *left_node = new BTNode<T>(left_data);
            q.push(left_node);
            current_node->left = left_node;
        }
        if (right_data != -1)
        {
            BTNode<T> *right_node = new BTNode<T>(right_data);
            q.push(right_node);
            current_node->right = right_node;
        }
    }

    return root;
}

template <class T>
void print_binary_tree_level_wise(BTNode<T> *root) // Level order traversal
{
    if (root == NULL)
        return;
    
    /*
    Steps
    1. Create and push root node
    while !q.empty()
        2. Pop node from q
        3. Print node
        4. Push left child of current node (if exists) in q
        5. Push right child of current node (if exists) in q
    */

   // Push root node
   queue<BTNode<T>*> q;
   q.push(root);
   q.push(NULL); // NULL is used to differentiate levels

   while (!q.empty())
   {
        // Pop node from q
        BTNode<T> *current_node = q.front();
        q.pop();

        if (current_node == NULL)
        {
            cout << endl; // Prev level is finished so move to next line
            if (!q.empty())
                q.push(NULL);
            continue;
        }

        // Print node
        cout << "[" << left << setw(3) << current_node->data << ": ";

        // Left child
        if (current_node->left)
        {
            cout << "L=" << left << setw(3) << current_node->left->data;
            q.push(current_node->left);
        }
        // Right child
        if (current_node->right)
        {
            cout << "R=" << left << setw(3) << current_node->right->data;
            q.push(current_node->right);
        }
        cout << "], ";
   }
   cout << endl;
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

template <class T>
int count_nodes_in_binary_tree(BTNode<T> *root)
{
    if (root == NULL)
        return 0;
    
    int nodes_count = 1;
    // Count nodes in left subtree
    nodes_count += count_nodes_in_binary_tree(root->left);
    // Count nodes in right subtree
    nodes_count += count_nodes_in_binary_tree(root->right);
    return nodes_count;
}

template <class T>
int max_depth_of_binary_tree(BTNode<T> *root)
{
    // aka Height of binary tree
    if (root == NULL)
        return 0;
    return 1 + max(
        max_depth_of_binary_tree(root->left),
        max_depth_of_binary_tree(root->right)
    );
}

int main() 
{
    // ########################## //
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    // Take tree input recursive
    // Test input 1 = 2 3 8 -1 -1 5 9 -1 -1 -1 7 1 -1 -1 6 -1 4 -1 -1
    // Test input 2 = 15 21 8 11 -1 -1 2 -1 -1 7 4 -1 -1 1 -1 -1 6 3 37 -1 -1 19 -1 -1 20 5 -1 -1 10 -1 -1

    // Take tree input level wise
    // Test input 1 = 2 3 7 8 5 1 6 -1 -1 9 -1 -1 -1 -1 4 -1 -1 -1 -1
    // Test input 2 = 15 21 6 8 7 3 20 11 2 4 1 37 19 5 10 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // Test input 3 = 2 3 -1 8 5 -1 -1 9 -1 -1 7 1 6 -1 -1 -1 4 -1 -1

    cout << "Enter tree level wise: ";
    BTNode<int> *root_tree1 = take_binary_tree_input_level_wise<int>();
    cout << "Enter tree level wise: ";
    BTNode<int> *root_tree2 = take_binary_tree_input_level_wise<int>();
    cout << "Enter tree level wise: ";
    BTNode<int> *root_tree3 = take_binary_tree_input_level_wise<int>();

    cout << "Tree 1\n";
    print_binary_tree_level_wise(root_tree1);

    cout << "\n\n";
    cout << "Tree 2\n";
    print_binary_tree_level_wise(root_tree2);

    cout << "\n\n";
    cout << "Tree 3\n";
    print_binary_tree_level_wise(root_tree3); 

    cout << "\n\n";
    cout << "Nodes tree 1 = " << count_nodes_in_binary_tree(root_tree1) << endl;
    cout << "Nodes tree 2 = " << count_nodes_in_binary_tree(root_tree2) << endl;
    cout << "Nodes tree 3 = " << count_nodes_in_binary_tree(root_tree3) << endl;

    cout << "\n\n";
    cout << "Max depth (height) of tree 1 = " << max_depth_of_binary_tree(root_tree1) << endl;
    cout << "Max depth (height) of tree 2 = " << max_depth_of_binary_tree(root_tree2) << endl;
    cout << "Max depth (height) of tree 3 = " << max_depth_of_binary_tree(root_tree3) << endl;

    return 0;
}