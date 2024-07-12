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
vector<T> get_root_to_node_path(BTNode<T> *root, T data)
{
    if (root == NULL)
    {
        vector<T> v;
        return v;
    }

    if (root->data == data)
    {
        vector<T> v;
        v.push_back(root->data);
        return v;
    }

    vector<T> v;
    v.push_back(root->data);
    // Check left subtree
    if (is_node_exists_in_binary_tree(root->left, data))
    {
        vector<T> left_subtree_path = get_root_to_node_path(root->left, data);
        v.insert(
            v.end(),
            left_subtree_path.begin(),
            left_subtree_path.end()
        );
    }
    // Check right subtree
    else if (is_node_exists_in_binary_tree(root->right, data))
    {
        vector<T> right_subtree_path = get_root_to_node_path(root->right, data);
        v.insert(
            v.end(),
            right_subtree_path.begin(),
            right_subtree_path.end()
        );
    }
    return v;
}

// Better approach
template <class T>
pair<vector<T>, bool> root_to_node_path_helper(BTNode<T> *root, T data, vector<T> v={})
{
    pair<vector<T>, bool> p;
    if (root == NULL)
    {
        p.first = v;
        p.second = false;
        return p;
    }

    if (root->data == data)
    {
        v.push_back(root->data);
        p.first = v;
        p.second = true;
        return p;
    }

    v.push_back(root->data);
    pair<vector<T>, bool> left_pair = root_to_node_path_helper(root->left, data, v);
    pair<vector<T>, bool> right_pair = root_to_node_path_helper(root->right, data, v);

    if (left_pair.second==false && right_pair.second==false)
    {
        v.pop_back();
        p.first = v;
        p.second = false;
        return p;
    }

    if (left_pair.second)
    {
        return left_pair;
    }
    return right_pair;
}

template <class T>
vector<T> get_root_to_node_path_v2(BTNode<T> *root, T data)
{
    pair<vector<T>, bool> p = root_to_node_path_helper(root, data);
    vector<T> v = p.first;
    return v;
}

template <class T>
void display_path(vector<T> v)
{
    for (int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
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

    BTNode<int> *r1 = take_binary_tree_input_level_wise<int>();
    print_binary_tree_level_wise(r1);
    vector<int> path1 = get_root_to_node_path(r1, 7);
    display_path(path1);
    cout << "\n\n";

    BTNode<int> *r2 = take_binary_tree_input_level_wise<int>();
    print_binary_tree_level_wise(r2);
    vector<int> path2 = get_root_to_node_path(r2, 19);
    display_path(path2);
    cout << "\n\n";

    BTNode<int> *r3 = take_binary_tree_input_level_wise<int>();
    print_binary_tree_level_wise(r3);
    vector<int> path3 = get_root_to_node_path(r3, 12);
    display_path(path3);
    vector<int> path4 = get_root_to_node_path(r3, 13);
    display_path(path4);
    cout << "\n\n";

    cout << "\nRoot to node path V2\n\n";
    vector<int> path5 = get_root_to_node_path_v2(r3, 12);
    display_path(path5);
    vector<int> path6 = get_root_to_node_path_v2(r3, 13);
    display_path(path6);
    vector<int> path7 = get_root_to_node_path_v2(r3, 14);
    display_path(path7);
    vector<int> path8 = get_root_to_node_path_v2(r2, 10);
    display_path(path8);
    vector<int> path9 = get_root_to_node_path_v2(r1, 9);
    display_path(path9);
    cout << "\n\n";

    return 0;
}