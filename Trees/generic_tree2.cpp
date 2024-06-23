#include <bits/stdc++.h>
using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

template <class T>
void print_tree_level_wise(TreeNode<T>* root)
{
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
        return;
    }

    queue<TreeNode<T>*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<T> *tree_node = q.front();
        q.pop();

        cout << setw(5) << tree_node->data << ": ";
        for (int i=0; i<tree_node->children.size(); i++)
        {
            TreeNode<T> *ith_child_node = tree_node->children[i];
            cout << setw(5) << ith_child_node->data << " ";
            q.push(ith_child_node);
        }
        cout << endl;
    }
}

template <class T>
TreeNode<T>* take_tree_input_level_wise()
{
    queue<TreeNode<T>*> q;
    TreeNode<T> *root = NULL;
    T data;
    int num_children;
    cout << "Enter root node data: ";
    cin >> data;
    cout << "Enter number of children for root node: ";
    cin >> num_children;
    root = new TreeNode<T>(data);
    vector<TreeNode<T>*> root_node_children(num_children);
    root->children = root_node_children;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<T> *current_tree_node = q.front();
        q.pop();

        int n = current_tree_node->children.size();
        cout << "Enter " << n << " children nodes data for node " << current_tree_node->data << endl;
        for (int i=0; i<n; i++)
        {
            T data;
            int num_children;
            cout << "Enter child " << i << " node data: ";
            cin >> data;
            cout << "Enter number of children for (child " << i << ") node " << data << ": ";
            cin >> num_children;

            // Create node
            TreeNode<T> *new_tree_node = new TreeNode<T>(data);
            vector<TreeNode<T>*> new_tree_node_children(num_children);
            new_tree_node->children = new_tree_node_children;

            // Create connection
            current_tree_node->children[i] = new_tree_node;

            // Push in queue
            q.push(new_tree_node);
        }
    }
    return root;
}

template <class T>
int count_nodes_in_tree(TreeNode<T> *root)
{
    if (root == NULL)
        return 0;
    
    int nodes_count = 1;
    for (int i=0; i<root->children.size(); i++)
    {
        nodes_count += count_nodes_in_tree(root->children[i]);
    }
    return nodes_count;
}

template <class T>
int get_height_of_tree_v1(TreeNode<T>* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int height = 1;
    int max_children_height = 0;
    for (int i=0; i<root->children.size(); i++)
    {
        max_children_height = max(
            max_children_height,
            get_height_of_tree_v1(root->children[i])
        );
    }
    height += max_children_height;
    return height;
}

template <class T>
void print_all_nodes_at_level_k_v1(TreeNode<T>* root, int k)
{
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
        return;
    }

    queue<TreeNode<T>*> q;
    q.push(root);
    queue<int> level_q;
    level_q.push(0);

    int level = 0;

    while (!q.empty())
    {
        TreeNode<T> *tree_node = q.front();
        q.pop();
        int current_level = level_q.front();
        level_q.pop();

        if (current_level == k)
            cout << setw(5) << tree_node->data << " ";

        for (int i=0; i<tree_node->children.size(); i++)
        {
            TreeNode<T> *ith_child_node = tree_node->children[i];
            q.push(ith_child_node);
            level_q.push(current_level + 1);
        }
    }
}

template <class T>
void print_all_nodes_at_level_k_v2(TreeNode<T>* root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << setw(5) << root->data << " ";
        return;
    }
    for (int i=0; i<root->children.size(); i++)
    {
        print_all_nodes_at_level_k_v2(root->children[i], k-1);
    }
}

template <class T>
void print_all_nodes_at_level_k_v3(TreeNode<T>* root, int k, int current_depth=0)
{
    if (root == NULL)
    {
        return;
    }
    if (current_depth == k)
    {
        cout << setw(5) << root->data << " ";
        return;
    }
    for (int i=0; i<root->children.size(); i++)
    {
        print_all_nodes_at_level_k_v3(root->children[i], k, current_depth+1);
    }
}

template <class T>
int count_leaf_nodes_in_tree(TreeNode<T>* root)
{
    if (root == NULL)
        return 0;
    
    if (root->children.size() == 0)
        return 1;

    int leaf_nodes_count = 0;
    for (int i=0; i<root->children.size(); i++)
    {
        leaf_nodes_count += count_leaf_nodes_in_tree(root->children[i]);
    }
    return leaf_nodes_count;
}

int main() 
{
    // ########################## //
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    // Tree examples
    // 7 4 5 3 1 2 4 1 16 4 23 1 11 2 2 1 3 0 10 0 26 3 30 0 29 2 28 1 27 2 6 0 31 0 32 0 33 0 34 0 35 0 36 0 37 0 38 0 39 0 8 0 9 0
    // 1 3 2 2 3 1 4 1 5 0 6 0 7 0 8 0

    TreeNode<int> *root = take_tree_input_level_wise<int>();
    cout << "\n\tTREE\n";
    print_tree_level_wise(root);
    cout << "\n\n";

    cout << "Total number of nodes in tree = " << count_nodes_in_tree(root) << "\n\n";

    int height = get_height_of_tree_v1(root);
    cout << "Height of tree = " << height << "\n\n";

    int level;
    cout << "Enter level number: ";
    cin >> level;
    if (level >= height)
    {
        cout << "Invalid level number provided. It should be less than height of the tree.";
    }
    else
    {
        cout << "All nodes at level " << level << " (v1)\n";
        print_all_nodes_at_level_k_v1(root, level);
        cout << "\n\n";
        cout << "All nodes at level " << level << " (v2)\n";
        print_all_nodes_at_level_k_v2(root, level);
        cout << "\n\n";
        cout << "All nodes at level " << level << " (v3)\n";
        print_all_nodes_at_level_k_v3(root, level);
    }
    cout << "\n\n";

    int leaf_nodes_count = count_leaf_nodes_in_tree(root);
    cout << "Leaf nodes in tree = " << leaf_nodes_count << "\n\n";

    return 0;
}