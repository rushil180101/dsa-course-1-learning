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
bool is_node_exists_in_binary_tree(BTNode<T> *root, T data)
{
    if (root == NULL)
        return false;
    
    if (root->data == data)
        return true;
    
    // search in left subtree
    bool is_node_exists_in_left_subtree = is_node_exists_in_binary_tree(root->left, data);
    bool is_node_exists_in_right_subtree = is_node_exists_in_binary_tree(root->right, data);
    return (is_node_exists_in_left_subtree || is_node_exists_in_right_subtree);
}

template <class T>
T min_value_in_binary_tree(BTNode<T> *root)
{
    if (root == NULL)
        return 0;
    
    T min_value = root->data;
    // Get min value from left subtree
    if (root->left)
    {
        T min_value_left_subtree = min_value_in_binary_tree(root->left);
        min_value = min(min_value, min_value_left_subtree);
    }
    // Get min value from right subtree
    if (root->right)
    {
        T min_value_right_subtree = min_value_in_binary_tree(root->right);
        min_value = min(min_value, min_value_right_subtree);
    }
    return min_value;
}

template <class T>
T max_value_in_binary_tree(BTNode<T> *root)
{
    if (root == NULL)
        return 0;
    
    T max_value = root->data;
    // Get max value from left subtree
    if (root->left)
    {
        T max_value_left_subtree = max_value_in_binary_tree(root->left);
        max_value = max(max_value, max_value_left_subtree);
    }
    // Get max value from right subtree
    if (root->right)
    {
        T max_value_right_subtree = max_value_in_binary_tree(root->right);
        max_value = max(max_value, max_value_right_subtree);
    }
    return max_value;
}

template <class T>
int count_leaf_nodes_in_binary_tree(BTNode<T> *root)
{
    if (root == NULL)
        return 0;
    
    if (root->left || root->right)
    {
        int leaf_nodes_ls = 0;
        int leaf_nodes_rs = 0;
        if (root->left)
            leaf_nodes_ls = count_leaf_nodes_in_binary_tree(root->left);
        if (root->right)
            leaf_nodes_rs = count_leaf_nodes_in_binary_tree(root->right);
        return leaf_nodes_ls + leaf_nodes_rs;
    }
    return 1;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    // Take tree input level wise
    // Test input 1 = 2 3 7 8 5 1 6 -1 -1 9 -1 -1 -1 -1 4 -1 -1 -1 -1
    // Test input 2 = 15 21 6 8 7 3 20 11 2 4 1 37 19 5 10 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // Test input 3 = 2 3 -1 8 5 -1 -1 9 -1 -1 7 1 6 -1 -1 -1 4 -1 -1
    // Test input 4 = 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
    // Test input 5 = 1 2 2 -1 3 -1 3 -1 -1 -1 -1
    // Test input 6 = 2 5 5 3 4 4 3 7 8 6 1 1 6 8 7 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // Test input 7 = 2 5 5 6 3 6 3 -1 -1 -1 -1 -1 -1 -1 -1
    // Test input 8 = 2 5 5 6 3 3 6 -1 -1 -1 -1 -1 -1 -1 -1
    // Test input 9 = 2 5 5 4 3 3 4 -1 -1 6 -1 -1 6 -1 -1 -1 7 7 -1 9 8 8 9 -1 10 -1 -1 -1 -1 10 -1 11 -1 -1 11 -1 -1 -1 -1
    // Test input 10 = 2 5 5 4 3 3 4 -1 5 6 -1 -1 6 -1 5 -1 -1 -1 -1 -1 -1 -1 -1

    BTNode<int> *root_tree1 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree2 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree3 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree4 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree5 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree6 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree7 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree8 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree9 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree10 = take_binary_tree_input_level_wise<int>();

    // cout << "\n\n";
    // cout << "Tree 1\n";
    // print_binary_tree_level_wise(root_tree1);

    // cout << "\n\n";
    // cout << "Tree 2\n";
    // print_binary_tree_level_wise(root_tree2);

    // cout << "\n\n";
    // cout << "Tree 3\n";
    // print_binary_tree_level_wise(root_tree3);

    // cout << "\n\n";
    // cout << "Tree 4\n";
    // print_binary_tree_level_wise(root_tree4); 

    // cout << "\n\n";
    // cout << "Tree 5\n";
    // print_binary_tree_level_wise(root_tree5);

    // cout << "\n\n";
    // cout << "Tree 6\n";
    // print_binary_tree_level_wise(root_tree6);

    // cout << "\n\n";
    // cout << "Tree 7\n";
    // print_binary_tree_level_wise(root_tree7);

    // cout << "\n\n";
    // cout << "Tree 8\n";
    // print_binary_tree_level_wise(root_tree8);

    // cout << "\n\n";
    // cout << "Tree 9\n";
    // print_binary_tree_level_wise(root_tree9);

    // cout << "\n\n";
    // cout << "Tree 10\n";
    // print_binary_tree_level_wise(root_tree10);

    cout << "\n\n";
    cout << is_node_exists_in_binary_tree(root_tree1, 9) << endl; // 1
    cout << is_node_exists_in_binary_tree(root_tree1, 7) << endl; // 1
    cout << is_node_exists_in_binary_tree(root_tree1, 1) << endl; // 1
    cout << is_node_exists_in_binary_tree(root_tree1, 20) << endl; // 0
    cout << is_node_exists_in_binary_tree(root_tree1, 11) << endl; // 0

    cout << is_node_exists_in_binary_tree(root_tree9, 7) << endl; // 1
    cout << is_node_exists_in_binary_tree(root_tree9, 11) << endl; // 1
    cout << is_node_exists_in_binary_tree(root_tree9, 1) << endl; // 0
    cout << is_node_exists_in_binary_tree(root_tree9, 20) << endl; // 0
    cout << is_node_exists_in_binary_tree(root_tree9, 11) << endl; // 1

    cout << "\n\nMin value\n";
    cout << min_value_in_binary_tree(root_tree1) << endl; //1
    cout << min_value_in_binary_tree(root_tree2) << endl; //1
    cout << min_value_in_binary_tree(root_tree3) << endl; //1
    cout << min_value_in_binary_tree(root_tree4) << endl; //1
    cout << min_value_in_binary_tree(root_tree5) << endl; //1
    cout << min_value_in_binary_tree(root_tree6) << endl; //1
    cout << min_value_in_binary_tree(root_tree7) << endl; //2
    cout << min_value_in_binary_tree(root_tree8) << endl; //2
    cout << min_value_in_binary_tree(root_tree9) << endl; //2
    cout << min_value_in_binary_tree(root_tree10) << endl; //4

    cout << "\n\nMax value\n";
    cout << max_value_in_binary_tree(root_tree1) << endl; //9
    cout << max_value_in_binary_tree(root_tree2) << endl; //37
    cout << max_value_in_binary_tree(root_tree3) << endl; //9
    cout << max_value_in_binary_tree(root_tree4) << endl; //4
    cout << max_value_in_binary_tree(root_tree5) << endl; //3
    cout << max_value_in_binary_tree(root_tree6) << endl; //8
    cout << max_value_in_binary_tree(root_tree7) << endl; //6
    cout << max_value_in_binary_tree(root_tree8) << endl; //6
    cout << max_value_in_binary_tree(root_tree9) << endl; //11
    cout << max_value_in_binary_tree(root_tree10) << endl; //60

    cout << "\n\nLeaf nodes\n";
    cout << count_leaf_nodes_in_binary_tree(root_tree1) << endl; //4
    cout << count_leaf_nodes_in_binary_tree(root_tree2) << endl; //8
    cout << count_leaf_nodes_in_binary_tree(root_tree3) << endl; //3
    cout << count_leaf_nodes_in_binary_tree(root_tree4) << endl;
    cout << count_leaf_nodes_in_binary_tree(root_tree5) << endl;
    cout << count_leaf_nodes_in_binary_tree(root_tree6) << endl;
    cout << count_leaf_nodes_in_binary_tree(root_tree7) << endl;
    cout << count_leaf_nodes_in_binary_tree(root_tree8) << endl;
    cout << count_leaf_nodes_in_binary_tree(root_tree9) << endl;
    cout << count_leaf_nodes_in_binary_tree(root_tree10) << endl;

    return 0;
}