#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* take_ll_input() // Inserting at tail
{
    int input;
    cin >> input;

    Node *head = NULL;
    Node *temp = NULL;

    while (input != -1)
    {
        Node *node = new Node(input);
        if (head == NULL)
        {
            head = node;
            temp = node;
        }
        else
        {
            temp->next = node;
            temp = node;
        }
        cin >> input;
    }
    return head;
}

void print_ll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int get_ll_length(Node *n) // Recursive
{
    if (n == NULL)
    {
        return 0;
    }
    return 1 + get_ll_length(n->next);
}

bool is_present(Node *head, int data)
{
    if (head == NULL)
    {
        return false;
    }
    while (head)
    {
        if (head->data == data)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool is_present_recursive(Node *head, int data)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->data == data)
    {
        return true;
    }
    return is_present_recursive(head->next, data);
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Node *h1 = take_ll_input();
    Node *h2 = take_ll_input();
    Node *h3 = take_ll_input();
    Node *h4 = take_ll_input();
    Node *h5 = take_ll_input();

    cout << get_ll_length(h1) << endl; // 5
    cout << get_ll_length(h2) << endl; // 0
    cout << get_ll_length(h3) << endl; // 1
    cout << get_ll_length(h4) << endl; // 4
    cout << get_ll_length(h5) << endl; // 10
    cout << endl;

    Node *h6 = take_ll_input();
    Node *h7 = take_ll_input();
    Node *h8 = take_ll_input();
    Node *h9 = take_ll_input();
    Node *h10 = take_ll_input();
    Node *h11 = take_ll_input();

    cout << "Iterative" << endl;
    cout << is_present(h6, 5) << endl; // 1
    cout << is_present(h7, 5) << endl; // 0
    cout << is_present(h8, -1) << endl; // 0
    cout << is_present(h9, 0) << endl; // 1
    cout << is_present(h10, 1) << endl; // 1
    cout << is_present(h11, 1) << endl; // 0
    cout << endl;

    cout << "Recursive" << endl;
    cout << is_present_recursive(h6, 5) << endl; // 1
    cout << is_present_recursive(h7, 5) << endl; // 0
    cout << is_present_recursive(h8, -1) << endl; // 0
    cout << is_present_recursive(h9, 0) << endl; // 1
    cout << is_present_recursive(h10, 1) << endl; // 1
    cout << is_present_recursive(h11, 1) << endl; // 0

    return 0;
}