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
bool search_in_bst_recursive(BSTNode<T> *root, T search_key)
{
    // Recusrive approach
    if (root==NULL)
        return false;
    
    if (root->data==search_key)
        return true;
    
    if (search_key<root->data)
    {
        // Search in left subtree
        return search_in_bst_recursive(root->left, search_key);
    }
    
    // Search in right subtree
    return search_in_bst_recursive(root->right, search_key);
}

template <class T>
bool search_in_bst_iterative(BSTNode<T> *root, T search_key)
{
    // Iterative approach
    while (root)
    {
        if (root->data==search_key)
            return true;
        
        if (root->data>search_key)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

template <class T>
int range_sum_in_bst(BSTNode<T> *root, T min_val, T max_val, int s=0)
{
    if (root==NULL)
        return s;
    
    if (root->data>=min_val && root->data<=max_val)
        s += root->data;
    
    if (root->data>max_val)
    {
        s += range_sum_in_bst(root->left, min_val, max_val);
    }
    else if (root->data<min_val)
    {
        s += range_sum_in_bst(root->right, min_val, max_val);
    }
    else
    {
        s += range_sum_in_bst(root->left, min_val, max_val);
        s += range_sum_in_bst(root->right, min_val, max_val);
    }
    return s;
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

    print_bst_level_wise(root4);
    print_bst_level_wise(root5);
    print_bst_level_wise(root6);

    // cout << search_in_bst_recursive(root1, 5) << endl;
    // cout << search_in_bst_recursive(root2, 1) << endl;
    // cout << search_in_bst_recursive(root3, 4) << endl;
    // cout << search_in_bst_recursive(root1, 20) << endl;
    // cout << search_in_bst_recursive(root2, 8) << endl;
    // cout << search_in_bst_recursive(root3, 9) << endl;

    // cout << search_in_bst_iterative(root1, 5) << endl;
    // cout << search_in_bst_iterative(root2, 1) << endl;
    // cout << search_in_bst_iterative(root3, 4) << endl;
    // cout << search_in_bst_iterative(root1, 20) << endl;
    // cout << search_in_bst_iterative(root2, 8) << endl;
    // cout << search_in_bst_iterative(root3, 9) << endl;

    cout << range_sum_in_bst(root4, 7, 15) << endl; // 32
    cout << range_sum_in_bst(root5, 6, 10) << endl; // 23
    cout << range_sum_in_bst(root6, 20, 30) << endl; // 50

    return 0;
}