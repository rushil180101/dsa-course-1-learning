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
bool is_symmetric_binary_tree_v1(BTNode<T> *root)
{
    if (root == NULL)
        return true;
    
    queue<BTNode<T>*> q;
    q.push(root);
    q.push(NULL);

    vector<T> level_nodes;
    vector<int> level_nodes_positions;
    while (!q.empty())
    {
        BTNode<T> *current_node = q.front();
        q.pop();

        if (current_node == NULL) // level change
        {
            if (!q.empty())
                q.push(NULL);
            
            // Check if level nodes vector is palindrome
            for (int i=0; i<level_nodes.size(); i++)
            {
                if (
                    (level_nodes[i] != level_nodes[level_nodes.size()-i-1])
                    || (level_nodes_positions[i] == level_nodes_positions[level_nodes_positions.size()-i-1])
                )
                    return false;
            }

            level_nodes.clear();
            level_nodes_positions.clear();
            continue;
        }

        if (current_node->left)
        {
            q.push(current_node->left);
            level_nodes.push_back(current_node->left->data);
            level_nodes_positions.push_back(0);
        }
        
        if (current_node->right)
        {
            q.push(current_node->right);
            level_nodes.push_back(current_node->right->data);
            level_nodes_positions.push_back(1);
        }
    }
    return true;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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

    BTNode<int> *root_tree1 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree2 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree3 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree4 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree5 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree6 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree7 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree8 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree9 = take_binary_tree_input_level_wise<int>();
    BTNode<int> *root_tree10 = take_binary_tree_input_level_wise<int>();

    cout << "\n\n";
    cout << "Tree 1\n";
    print_binary_tree_level_wise(root_tree1);

    cout << "\n\n";
    cout << "Tree 2\n";
    print_binary_tree_level_wise(root_tree2);

    cout << "\n\n";
    cout << "Tree 3\n";
    print_binary_tree_level_wise(root_tree3);

    cout << "\n\n";
    cout << "Tree 4\n";
    print_binary_tree_level_wise(root_tree4); 

    cout << "\n\n";
    cout << "Tree 5\n";
    print_binary_tree_level_wise(root_tree5);

    cout << "\n\n";
    cout << "Tree 6\n";
    print_binary_tree_level_wise(root_tree6);

    cout << "\n\n";
    cout << "Tree 7\n";
    print_binary_tree_level_wise(root_tree7);

    cout << "\n\n";
    cout << "Tree 8\n";
    print_binary_tree_level_wise(root_tree8);

    cout << "\n\n";
    cout << "Tree 9\n";
    print_binary_tree_level_wise(root_tree9);

    cout << "\n\n";
    cout << "Tree 10\n";
    print_binary_tree_level_wise(root_tree10);

    cout << "\n\n";
    cout << "Is symmetric tree 1 = " << is_symmetric_binary_tree_v1<int>(root_tree1) << endl;
    cout << "Is symmetric tree 2 = " << is_symmetric_binary_tree_v1<int>(root_tree2) << endl;
    cout << "Is symmetric tree 3 = " << is_symmetric_binary_tree_v1<int>(root_tree3) << endl;
    cout << "Is symmetric tree 4 = " << is_symmetric_binary_tree_v1<int>(root_tree4) << endl;
    cout << "Is symmetric tree 5 = " << is_symmetric_binary_tree_v1<int>(root_tree5) << endl;
    cout << "Is symmetric tree 6 = " << is_symmetric_binary_tree_v1<int>(root_tree6) << endl;
    cout << "Is symmetric tree 7 = " << is_symmetric_binary_tree_v1<int>(root_tree7) << endl;
    cout << "Is symmetric tree 8 = " << is_symmetric_binary_tree_v1<int>(root_tree8) << endl;
    cout << "Is symmetric tree 9 = " << is_symmetric_binary_tree_v1<int>(root_tree9) << endl;
    cout << "Is symmetric tree 10 = " << is_symmetric_binary_tree_v1<int>(root_tree10) << endl;

    return 0;
}