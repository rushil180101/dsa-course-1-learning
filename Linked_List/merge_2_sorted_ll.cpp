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

Node* merged_2_sorted_linked_lists(Node *head1, Node *head2)
{
    if ((head1 == NULL) || (head2 == NULL))
    {
        return NULL;
    }

    Node *temp_h1 = head1;
    Node *temp_h2 = head2;
    Node *x, *y, *fh;

    if (temp_h1->data <= temp_h2->data)
    {
        fh = head1;
    }
    else{
        fh = head2;
    }

    while (temp_h1 && temp_h2)
    {

        if (temp_h1->data < temp_h2->data)
        {
            while (temp_h1->next && (temp_h1->next->data <= temp_h2->data))
            {
                temp_h1 = temp_h1->next;
            }
            x = temp_h1->next;
            y = temp_h2->next;

            if ((temp_h1->next) && (temp_h2->next) && (temp_h1->next->data < temp_h2->next->data))
                temp_h2->next = temp_h1->next;
            temp_h1->next = temp_h2;
            
        }
        else if (temp_h1->data > temp_h2->data)
        {
            while (temp_h2->next && (temp_h2->next->data <= temp_h1->data))
            {
                temp_h2 = temp_h2->next;
            }
            x = temp_h1->next;
            y = temp_h2->next;

            if ((temp_h1->next) && (temp_h2->next) && (temp_h2->next->data < temp_h1->next->data))
                temp_h1->next = temp_h2->next;
            temp_h2->next = temp_h1;
        }
        else
        {
            x = temp_h1->next;
            y = temp_h2->next;

            temp_h1->next = temp_h2;
            if (x || y)
            {
                if (x && y)
                {
                    if (x->data <= y->data)
                    {
                        temp_h2->next = x;
                    }
                    else
                    {
                        temp_h2->next = y;
                    } 
                }
                else if (x)
                {
                    temp_h2->next = x;
                }
                else
                {
                    temp_h2->next = y;
                }
            }
        }
        temp_h1 = x;
        temp_h2 = y;
    }
    return fh;
}

Node* merged_2_sorted_linked_lists_recursive(Node *head1, Node *head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data < head2->data)
    {
        Node *final_head = head1;
        final_head->next = merged_2_sorted_linked_lists_recursive(
            head1->next,
            head2
        );
        return final_head;
    }
    
    Node *final_head = head2;
    final_head->next = merged_2_sorted_linked_lists_recursive(
        head1,
        head2->next
    );
    return final_head;
}

int main()
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Node *l1, *l2, *x;

    for (int i=0; i<8; i++)
    {
        l1 = take_ll_input();
        l2 = take_ll_input();
        print_ll(l1);
        print_ll(l2);
        x = merged_2_sorted_linked_lists(l1, l2);
        print_ll(x);
        cout << endl;
    }

    cout << "\n--------------------------------------------------------\n\n";

    Node *h1, *h2, *y;
    for (int i=0; i<8; i++)
    {
        h1 = take_ll_input();
        h2 = take_ll_input();
        print_ll(h1);
        print_ll(h2);
        y = merged_2_sorted_linked_lists_recursive(h1, h2);
        print_ll(y);
        cout << endl;
    }

    return 0;
}