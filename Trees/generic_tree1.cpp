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

template <class T>
TreeNode<T>* take_tree_input_v1()
{
    T root_data;
    cout << "Enter root data: ";
    cin >> root_data;
    TreeNode<T>* root = new TreeNode<T>(root_data);
    int num_children;
    cout << "Enter the number of children of TreeNode(" << root_data << "): ";
    cin >> num_children;
    for (int i=0; i<num_children; i++)
    {
        root->children.push_back(take_tree_input_v1<T>());
    }
    return root;
}

int main() 
{
    // ########################## //
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *n2 = new TreeNode<int>(2);
    TreeNode<int> *n3 = new TreeNode<int>(3);
    TreeNode<int> *n4 = new TreeNode<int>(4);
    TreeNode<int> *n5 = new TreeNode<int>(5);
    TreeNode<int> *n6 = new TreeNode<int>(6);
    TreeNode<int> *n7 = new TreeNode<int>(7);

    root->children.push_back(n2);
    root->children.push_back(n3);
    root->children.push_back(n4);

    n3->children.push_back(n5);
    n3->children.push_back(n6);

    n4->children.push_back(n7);

    print_tree_v1(root);

    cout << "\n\nTaking tree input\n\n";
    TreeNode<int>* r1 = take_tree_input_v1<int>();
    print_tree_v1(r1);

    return 0;
}