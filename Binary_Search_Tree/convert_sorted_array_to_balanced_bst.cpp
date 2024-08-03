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
BSTNode<T>* convert_sorted_array_to_bst(vector<T> v, int s, int e)
{
    if (s>e)
        return NULL;

    int m = (s + e) / 2;
    T root_data = v[m];
    BSTNode<T> *root = new BSTNode<T>(root_data);
    root->left = convert_sorted_array_to_bst(v, s, m-1);
    root->right = convert_sorted_array_to_bst(v, m+1, e);
    return root;
}

int main()
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //
    
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    vector<int> v3 = {2, 3, 4, 5, 6, 7};
    vector<char> v4 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    vector<int> v5 = {-10, -3, 0, 5, 9};

    BSTNode<int> *root1 = convert_sorted_array_to_bst(v1, 0, v1.size()-1);
    BSTNode<int> *root2 = convert_sorted_array_to_bst(v2, 0, v2.size()-1);
    BSTNode<int> *root3 = convert_sorted_array_to_bst(v3, 0, v3.size()-1);
    BSTNode<char> *root4 = convert_sorted_array_to_bst(v4, 0, v4.size()-1);
    BSTNode<int> *root5 = convert_sorted_array_to_bst(v5, 0, v5.size()-1);

    print_bst_level_wise(root1);
    cout << "\n\n";
    print_bst_level_wise(root2);
    cout << "\n\n";
    print_bst_level_wise(root3);
    cout << "\n\n";
    print_bst_level_wise(root4);
    cout << "\n\n";
    print_bst_level_wise(root5);
    cout << "\n\n";
    return 0;
}