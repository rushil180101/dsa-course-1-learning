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

int main() 
{
    // ########################## //
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    TreeNode<int> *root = take_tree_input_level_wise<int>();
    cout << "\n\tTREE\n";
    print_tree_level_wise<int>(root);

    return 0;
}