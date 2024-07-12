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
int max_depth_of_binary_tree(BTNode<T> *root)
{
    // aka Height of binary tree
    if (root == NULL)
        return 0;
    return 1 + max(
        max_depth_of_binary_tree(root->left),
        max_depth_of_binary_tree(root->right)
    );
}

template <class T>
int get_diameter_of_binary_tree(BTNode<T> *root)
{
    if (root == NULL)
        return 0;

    int diameter = 0;
    int left_subtree_diameter = 0;
    int right_subtree_diameter = 0;
    if (root->left)
    {
        diameter += max_depth_of_binary_tree(root->left);
        left_subtree_diameter = get_diameter_of_binary_tree(root->left);
    }
    if (root->right)
    {
        diameter += max_depth_of_binary_tree(root->right);
        right_subtree_diameter = get_diameter_of_binary_tree(root->right);
    }

    diameter = max(
        diameter, max(left_subtree_diameter, right_subtree_diameter)
    );
    return diameter;
}
/////////////////////////////////////////////////////////////////////


// Better approach

template <class T>
pair<int, int> get_height_diameter_of_binary_tree(BTNode<T> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    // Get height and diameter of left subtree
    pair<int, int> left_pair = get_height_diameter_of_binary_tree(root->left);

    // Get height and diameter of right subtree
    pair<int, int> right_pair = get_height_diameter_of_binary_tree(root->right);

    int left_height = left_pair.first;
    int left_diameter = left_pair.second;
    int right_height = right_pair.first;
    int right_diameter = right_pair.second;

    int height = 1 + max(left_height, right_height);
    int diameter = max(
        left_height + right_height,
        max(left_diameter, right_diameter)
    );
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

template <class T>
int get_diameter_of_binary_tree_v2(BTNode<T> *root)
{
    pair<int, int> p = get_height_diameter_of_binary_tree(root);
    return p.second;
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
    int d1 = get_diameter_of_binary_tree(r1);
    print_binary_tree_level_wise(r1);
    cout << "Diameter = " << d1 << "\n\n\n";

    BTNode<int> *r2 = take_binary_tree_input_level_wise<int>();
    int d2 = get_diameter_of_binary_tree(r2);
    print_binary_tree_level_wise(r2);
    cout << "Diameter = " << d2 << "\n\n\n";

    BTNode<int> *r3 = take_binary_tree_input_level_wise<int>();
    int d3 = get_diameter_of_binary_tree(r3);
    print_binary_tree_level_wise(r3);
    cout << "Diameter = " << d3 << "\n\n\n";

    BTNode<int> *r4 = take_binary_tree_input_level_wise<int>();
    int d4 = get_diameter_of_binary_tree(r4);
    print_binary_tree_level_wise(r4);
    cout << "Diameter = " << d4 << "\n\n\n";

    BTNode<int> *r5 = take_binary_tree_input_level_wise<int>();
    int d5 = get_diameter_of_binary_tree(r5);
    print_binary_tree_level_wise(r5);
    cout << "Diameter = " << d5 << "\n\n\n";

    BTNode<int> *r6 = take_binary_tree_input_level_wise<int>();
    int d6 = get_diameter_of_binary_tree(r6);
    print_binary_tree_level_wise(r6);
    cout << "Diameter = " << d6 << "\n\n\n";

    BTNode<int> *r7 = take_binary_tree_input_level_wise<int>();
    int d7 = get_diameter_of_binary_tree_v2(r7);
    print_binary_tree_level_wise(r7);
    cout << "Diameter v2 = " << d7 << "\n\n\n";

    BTNode<int> *r8 = take_binary_tree_input_level_wise<int>();
    int d8 = get_diameter_of_binary_tree_v2(r8);
    print_binary_tree_level_wise(r8);
    cout << "Diameter v2 = " << d8 << "\n\n\n";

    return 0;
}