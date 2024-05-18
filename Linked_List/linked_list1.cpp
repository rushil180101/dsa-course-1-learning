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

Node* take_ll_input_v2() // Inserting at head
{
    int input;
    cin >> input;

    Node *head = NULL;
    Node *tail = NULL;
    while (input != -1)
    {
        Node *n = new Node(input);
        if (head == NULL) // First element
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        cin >> input;
    }
    return head;
}

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

int get_ith_node(Node *head, int idx)
{
    if (idx < 0)
    {
        return -1;
    }
    int i = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (i == idx)
        {
            return (temp->data);
        }
        temp = temp->next;
        i++;
    }
    return -1;    
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
    Node *hx = take_ll_input();

    print_ll(h1);
    print_ll(h2);
    print_ll(h3);
    print_ll(h4);
    print_ll(hx);

    cout << "\n\nInserting at head\n\n";

    Node *h5 = take_ll_input_v2();
    Node *h6 = take_ll_input_v2();
    Node *h7 = take_ll_input_v2();
    Node *hy = take_ll_input_v2();

    print_ll(h5);
    print_ll(h6);
    print_ll(h7);
    print_ll(hy);

    cout << "\n\nLL length\n\n";
    cout << get_ll_length(h1) << endl; //5
    cout << get_ll_length(h2) << endl; //10
    cout << get_ll_length(h3) << endl; //8
    cout << get_ll_length(h4) << endl; //8
    cout << get_ll_length(hx) << endl; //0

    cout << get_ll_length(h5) << endl; //12
    cout << get_ll_length(h6) << endl; //11
    cout << get_ll_length(h7) << endl; //8
    cout << get_ll_length(hy) << endl; //0

    cout << "\n\nGetting ith node\n\n";
    Node *h11 = take_ll_input();
    Node *h12 = take_ll_input();

    cout << get_ith_node(h11, 0) << endl; //1
    cout << get_ith_node(h11, 1) << endl; //2
    cout << get_ith_node(h11, 2) << endl; //3
    cout << get_ith_node(h11, 7) << endl; //8
    cout << get_ith_node(h11, 8) << endl; //-1
    cout << get_ith_node(h11, 10) << endl; //-1
    cout << get_ith_node(h11, -1) << endl; //-1
    cout << get_ith_node(h11, -2) << endl; //-1
    cout << endl;

    cout << get_ith_node(h12, 2) << endl; //-1
    cout << get_ith_node(h12, 0) << endl; //10
    cout << get_ith_node(h12, 1) << endl; //20
    cout << get_ith_node(h12, -1) << endl; //-1

    return 0;
}