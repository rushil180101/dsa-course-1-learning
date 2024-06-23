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
    ~TreeNode()
    {
        // Destructor will be called before actually deleting the node
        // Hence we can utilize destructor to delete all children nodes first

        // First delete all children
        for (int i=0; i<this->children.size(); i++)
        {
            delete this->children[i];
        }
        cout << "Destructor - Delete " << this->data << endl;
    }
};

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
void print_tree_v1(TreeNode<T>* root)
{
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
        return;
    }

    cout << setw(5) << root->data << ": ";
    for (int i=0; i<root->children.size(); i++)
    {
        cout << setw(5) << (root->children[i])->data << " ";
    }
    cout << endl;
    for (int i=0; i<root->children.size(); i++)
    {
        print_tree_v1(root->children[i]);
    }
}

// Delete tree - Use post order traversal, i.e., first delete children, then delete root
template <class T>
void delete_tree(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    
    for (int i=0; i<root->children.size(); i++)
    {
        delete_tree(root->children[i]);
    }
    cout << "Delete " << root->data << endl;
    delete root;
}

int main()
{
    TreeNode<int> *root = take_tree_input_level_wise<int>();
    cout << "\nTREE (Recursive)\n";
    print_tree_v1(root);
    cout << endl;
    
    // delete_tree(root);
    delete root;

    return 0;
}
