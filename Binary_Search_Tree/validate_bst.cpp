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
BSTNode<T>* take_bst_input_level_wise()
{
    T data;
    cin >> data;
    if (data == -1)
        return NULL;
    
    queue<BSTNode<T>*> q;
    BSTNode<T> *root = new BSTNode<T>(data);
    q.push(root);

    while (!q.empty())
    {
        BSTNode<T> *current_node = q.front();
        q.pop();

        T left_data, right_data;
        cin >> left_data >> right_data;

        if (left_data != -1)
        {
            BSTNode<T> *left_node = new BSTNode<T>(left_data);
            q.push(left_node);
            current_node->left = left_node;
        }
        if (right_data != -1)
        {
            BSTNode<T> *right_node = new BSTNode<T>(right_data);
            q.push(right_node);
            current_node->right = right_node;
        }
    }

    return root;
}

template <class T>
void print_bst_level_wise(BSTNode<T> *root) // Level order traversal
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
   queue<BSTNode<T>*> q;
   q.push(root);
   q.push(NULL); // NULL is used to differentiate levels

   while (!q.empty())
   {
        // Pop node from q
        BSTNode<T> *current_node = q.front();
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

/////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void get_inorder_traversal(BSTNode<T> *root, vector<T> &v)
{
    if (root==NULL)
        return;

    get_inorder_traversal(root->left, v);
    v.push_back(root->data);
    get_inorder_traversal(root->right, v);
}

template <class T>
bool is_tree_bst_v1(BSTNode<T> *root)
{
    if (root==NULL)
        return true;
    
    vector<T> inorder_traversal;
    get_inorder_traversal(root, inorder_traversal);

    for (int i=0; i<inorder_traversal.size()-1; i++)
    {
        if (inorder_traversal[i]>inorder_traversal[i+1])
            return false;
    }
    return true;
}

template <class T>
bool is_tree_bst_v2(
    BSTNode<T> *root,
    int min_val=INT_MIN,
    int max_val=INT_MAX
)
{
    if (root==NULL)
        return true;
    
    // Check data constraints for each node
    bool c1 = is_tree_bst_v2(root->left, min_val, root->data);
    bool c2 = is_tree_bst_v2(root->right, root->data, max_val);
    bool c3 = (root->data > min_val) && (root->data < max_val);
    return (c1 && c2 && c3);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    BSTNode<int> *root1 = take_bst_input_level_wise<int>();
    BSTNode<int> *root2 = take_bst_input_level_wise<int>();
    BSTNode<int> *root3 = take_bst_input_level_wise<int>();
    BSTNode<int> *root4 = take_bst_input_level_wise<int>();
    BSTNode<int> *root5 = take_bst_input_level_wise<int>();
    BSTNode<int> *root6 = take_bst_input_level_wise<int>();

    cout << "\n\nApproach-1\n\n";
    cout << is_tree_bst_v1(root1) << endl; // 1
    cout << is_tree_bst_v1(root2) << endl; // 0
    cout << is_tree_bst_v1(root3) << endl; // 1
    cout << is_tree_bst_v1(root4) << endl; // 0
    cout << is_tree_bst_v1(root5) << endl; // 1
    cout << is_tree_bst_v1(root6) << endl; // 0

    cout << "\n\nApproach-2\n\n";
    cout << is_tree_bst_v2(root1) << endl; // 1
    cout << is_tree_bst_v2(root2) << endl; // 0
    cout << is_tree_bst_v2(root3) << endl; // 1
    cout << is_tree_bst_v2(root4) << endl; // 0
    cout << is_tree_bst_v2(root5) << endl; // 1
    cout << is_tree_bst_v2(root6) << endl; // 0

    return 0;
}