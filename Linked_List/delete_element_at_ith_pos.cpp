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

// Avoid calculating length due to time complexity = O(n)
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

Node* delete_element_at_ith_position(
    Node *head,
    int position
)
{
    if (position<0 || head==NULL)
    {
        return head;
    }

    Node *temp_head = head;
    if (position==0)
    {
        head = head->next;

        temp_head->next = NULL; // Isolate the node
        delete temp_head;
        return head;
    }

    int idx = 0;
    while (idx!=position-1 && temp_head)
    {
        temp_head = temp_head->next;
        idx++;
    }
    if (temp_head && temp_head->next) // Imp - Need to check temp_head->next exists and is not NULL
    {
        Node *temp_node = temp_head->next;
        temp_head->next = temp_node->next;

        temp_node->next = NULL; // Isolate the node
        delete temp_node;
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
    Node *h2 = delete_element_at_ith_position(h1, 2);
    print_ll(h2); // 0 1 3 4 5 6 7

    Node *h3 = take_ll_input();
    Node *h4 = delete_element_at_ith_position(h3, 7);
    print_ll(h4); // 1 2 3 4 5 6 7 9

    Node *h5 = take_ll_input();
    Node *h6 = delete_element_at_ith_position(h5, 1);
    print_ll(h6); // 9 7 6 5 4 3 2 1

    Node *h7 = take_ll_input();
    Node *h8 = delete_element_at_ith_position(h7, 0);
    print_ll(h8); // 20 30 40 50 60 70

    Node *h9 = take_ll_input();
    Node *h10 = delete_element_at_ith_position(h9, 7);
    print_ll(h10); // 8 7 6 5 1 2 3

    Node *h11 = take_ll_input();
    Node *h12 = delete_element_at_ith_position(h11, -1);
    print_ll(h12); // 10 1 9 2 8 3 7 4 6 5

    Node *h13 = take_ll_input();
    Node *h14 = delete_element_at_ith_position(h13, 7);
    print_ll(h14); // 7 1 4 5 6 3 2
    return 0;
}