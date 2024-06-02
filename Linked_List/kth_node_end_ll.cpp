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

Node* remove_kth_node_from_end_of_ll(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *p1 = head;
    Node *p2 = head;
    int i = 0;
    while (i<k && p2)
    {
        p2 = p2->next;
        i++;
    }
    if (i != k)
    {
        return head;
    }
    if (p2 == NULL)
    {
        // Remove the first element
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    while (p2->next)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    Node *temp = p1->next;
    p1->next = p1->next->next;
    temp->next = NULL;
    delete temp;

    return head;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Node *l1 = take_ll_input();
    print_ll(l1);
    Node *n1 = remove_kth_node_from_end_of_ll(l1, 3);
    print_ll(n1);
    cout << endl;

    Node *l2 = take_ll_input();
    print_ll(l2);
    Node *n2 = remove_kth_node_from_end_of_ll(l2, 4);
    print_ll(n2);
    cout << endl;

    Node *l3 = take_ll_input();
    print_ll(l3);
    Node *n3 = remove_kth_node_from_end_of_ll(l3, 1);
    print_ll(n3);
    cout << endl;

    Node *l4 = take_ll_input();
    print_ll(l4);
    Node *n4 = remove_kth_node_from_end_of_ll(l4, 9);
    print_ll(n4);
    cout << endl;

    Node *l5 = take_ll_input();
    print_ll(l5);
    Node *n5 = remove_kth_node_from_end_of_ll(l5, 2);
    print_ll(n5);
    cout << endl;

    Node *l6 = take_ll_input();
    print_ll(l6);
    Node *n6 = remove_kth_node_from_end_of_ll(l6, 4);
    print_ll(n6);
    cout << endl;

    Node *l7 = take_ll_input();
    print_ll(l7);
    Node *n7 = remove_kth_node_from_end_of_ll(l7, 3);
    print_ll(n7);
    cout << endl;

    return 0;
}