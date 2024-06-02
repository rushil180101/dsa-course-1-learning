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

Node* reverse_linked_list(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *x = head;
    Node *y = head->next;
    while (x && y)
    {
        Node *temp1 = y;
        Node *temp2 = y->next;

        y->next = x;
        if (x == head)
        {
            x->next = NULL;
        }

        x = temp1;
        y = temp2;
    }
    return x;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Node *l1 = take_ll_input();
    print_ll(l1);
    Node *r1 = reverse_linked_list(l1);
    print_ll(r1);
    cout << endl;

    Node *l2 = take_ll_input();
    print_ll(l2);
    Node *r2 = reverse_linked_list(l2);
    print_ll(r2);
    cout << endl;

    Node *l3 = take_ll_input();
    print_ll(l3);
    Node *r3 = reverse_linked_list(l3);
    print_ll(r3);
    cout << endl;

    Node *l4 = take_ll_input();
    print_ll(l4);
    Node *r4 = reverse_linked_list(l4);
    print_ll(r4);
    cout << endl;

    Node *l5 = take_ll_input();
    print_ll(l5);
    Node *r5 = reverse_linked_list(l5);
    print_ll(r5);
    cout << endl;

    return 0;
}