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

// Avoid calculating length because of time complexity = O(n)
int get_ll_length(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* insert_element_at_ith_position(
    Node *head,
    int data,
    int position
)
{
    if (position<0)
    {
        return head;
    }

    int idx = 0;
    Node *temp_head = head;
    Node *new_node = new Node(data);
    if (position == 0)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        while (idx!=position-1 && temp_head)
        {
            temp_head = temp_head->next;
            idx++;
        }
        if (temp_head)
        {
            new_node->next = temp_head->next;
            temp_head->next = new_node;
        }
    }
    return head;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Node *h1 = take_ll_input();
    Node *h2 = insert_element_at_ith_position(h1, 10, 3);
    print_ll(h2); // 0 1 2 10 3 4 5 6 7

    Node *h3 = take_ll_input();
    Node *h4 = insert_element_at_ith_position(h3, 25, 1);
    print_ll(h4); // 1 25 2 3 4 5 6 7 8 9

    Node *h5 = take_ll_input();
    Node *h6 = insert_element_at_ith_position(h5, 35, 8);
    print_ll(h6); // 9 8 7 6 5 4 3 2 35 1

    Node *h7 = take_ll_input();
    Node *h8 = insert_element_at_ith_position(h7, 37, 0);
    print_ll(h8); // 37 10 20 30 40 50 60 70

    Node *h9 = take_ll_input();
    Node *h10 = insert_element_at_ith_position(h9, 73, 8);
    print_ll(h10); // 8 7 6 5 1 2 3 4 73

    Node *h11 = take_ll_input();
    Node *h12 = insert_element_at_ith_position(h11, 51, -3);
    print_ll(h12); // 10 1 9 2 8 3 7 4 6 5

    Node *h13 = take_ll_input();
    Node *h14 = insert_element_at_ith_position(h13, 67, 10);
    print_ll(h14); // 7 1 4 5 6 3 2
    return 0;
}