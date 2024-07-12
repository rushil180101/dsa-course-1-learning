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
BTNode<T>* construct_tree_from_preorder_and_inorder_traversal(
    vector<T> preorder,
    vector<T> inorder
)
{
    int m = preorder.size();
    int n = inorder.size();
    if (m==0 || n==0 || m!=n)
        return NULL;

    BTNode<T> *root = new BTNode<T>(preorder[0]);
    auto iter = find(inorder.begin(), inorder.end(), preorder[0]);
    if (iter == inorder.end())
        return NULL;
    
    int inorder_index = iter - inorder.begin();

    // Construct left preorder and inorder
    vector<T> left_preorder(inorder_index);
    vector<T> left_inorder(inorder_index);
    copy(
        preorder.begin() + 1,
        preorder.begin() + inorder_index + 1,
        left_preorder.begin()
    );
    copy(
        inorder.begin(),
        inorder.begin() + inorder_index,
        left_inorder.begin()
    );

    // Construct right preorder and inorder
    vector<T> right_preorder(n - inorder_index - 1);
    vector<T> right_inorder(n - inorder_index - 1);
    copy(
        preorder.begin() + 1 + inorder_index,
        preorder.begin() + m,
        right_preorder.begin()
    );
    copy(
        inorder.begin() + inorder_index + 1,
        inorder.begin() + n,
        right_inorder.begin()
    );

    // Construct left subtree
    root->left = construct_tree_from_preorder_and_inorder_traversal(
        left_preorder,
        left_inorder
    );
    
    // Construct right subtree
    root->right = construct_tree_from_preorder_and_inorder_traversal(
        right_preorder,
        right_inorder
    );

    return root;
}

template <class T>
BTNode<T>* construct_tree_from_postorder_and_inorder_traversal(
    vector<T> postorder,
    vector<T> inorder,
    int p_start,
    int p_end,
    int i_start,
    int i_end
)
{
    int m = postorder.size();
    int n = inorder.size();
    if (m==0 || n==0 || m!=n)
        return NULL;
    
    if (p_start>p_end || i_start>i_end)
        return NULL;
    
    T root_data = postorder[p_end];
    BTNode<T> *root = new BTNode<T>(root_data);

    int root_idx = -1;
    for (int i=0; i<n; i++)
    {
        if (inorder[i] == root_data)
        {
            root_idx = i;
            break;
        }
    }

    // Calculate required indices
    int left_i_start = i_start;
    int left_i_end = root_idx - 1;
    int left_p_start = p_start;
    int left_p_end = left_i_end - left_i_start + left_p_start;

    int right_i_start = root_idx + 1;
    int right_i_end = i_end;
    int right_p_end = p_end - 1;
    int right_p_start = right_p_end - right_i_end + right_i_start;

    // Construct left substree
    root->left = construct_tree_from_postorder_and_inorder_traversal(
        postorder,
        inorder,
        left_p_start,
        left_p_end,
        left_i_start,
        left_i_end
    );

    // Construct right subtree
    root->right = construct_tree_from_postorder_and_inorder_traversal(
        postorder,
        inorder,
        right_p_start,
        right_p_end,
        right_i_start,
        right_i_end
    );

    return root;
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

    vector<int> p1 = {2, 3, 5, 6, 7, 8, 4, 9, 10, 11};
    vector<int> i1 = {5, 7, 6, 8, 3, 2, 9, 4, 11, 10};
    BTNode<int> *r1 = construct_tree_from_preorder_and_inorder_traversal(
        p1,
        i1
    );
    print_binary_tree_level_wise(r1);

    cout << "\n\n";
    vector<int> p2 = {1, 2, 4, 3, 5, 7, 8, 6};
    vector<int> i2 = {4, 2, 1, 7, 5, 8, 3, 6};
    BTNode<int> *r2 = construct_tree_from_preorder_and_inorder_traversal(
        p2,
        i2
    );
    print_binary_tree_level_wise(r2);

    cout << "\n\n";
    vector<int> p3 = {3, 9, 20, 15, 7};
    vector<int> i3 = {9, 3, 15, 20, 7};
    BTNode<int> *r3 = construct_tree_from_preorder_and_inorder_traversal(
        p3,
        i3
    );
    print_binary_tree_level_wise(r3);

    ///////////////////////////////////

    cout << "\nContruct tree from postorder and inorder traversal\n\n";
    vector<int> post1 = {9, 15, 7, 20, 3};
    vector<int> in1 = {9, 3, 15, 20, 7};
    BTNode<int> *root1 = construct_tree_from_postorder_and_inorder_traversal(
        post1,
        in1,
        0,
        post1.size()-1,
        0,
        in1.size()-1
    );
    print_binary_tree_level_wise(root1);

    return 0;
}