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

Node* get_mid_point_of_linked_list(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    int l_length = 1, r_length = 1;

    Node *slow_ptr = head;
    Node *fast_ptr = head->next;
    Node *temp_head = head;

    while (slow_ptr)
    {
        while (fast_ptr)
        {
            fast_ptr = fast_ptr->next;
            r_length++;
        }
        if ((l_length == r_length) || (l_length == r_length + 1))
        {
            return slow_ptr;
        }

        slow_ptr = slow_ptr->next;
        l_length++;

        fast_ptr = slow_ptr->next;
        r_length = 1;
    }
    return NULL;
}

Node* get_mid_point_of_linked_list_v2_optimised(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow_ptr = head;
    Node *fast_ptr = head->next;

    while (fast_ptr && fast_ptr->next)
    {
        // Jump slow_ptr by 1
        slow_ptr = slow_ptr->next;

        // Jump fast_ptr by 2
        fast_ptr = fast_ptr->next->next;
    }
    if (fast_ptr)
    {
        return slow_ptr->next;
    }
    return slow_ptr;    
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
    Node *h6 = take_ll_input();
    Node *h7 = take_ll_input();
    Node *h8 = take_ll_input();

    print_ll(h1);
    cout << (get_mid_point_of_linked_list(h1))->data << "\n\n"; // 3
    print_ll(h2);
    cout << (get_mid_point_of_linked_list(h2))->data << "\n\n"; // 25
    print_ll(h3);
    cout << (get_mid_point_of_linked_list(h3))->data << "\n\n"; // 15
    print_ll(h4);
    cout << (get_mid_point_of_linked_list(h4))->data << "\n\n"; // 17
    print_ll(h5);
    cout << (get_mid_point_of_linked_list(h5))->data << "\n\n"; // 5
    print_ll(h6);
    cout << (get_mid_point_of_linked_list(h6))->data << "\n\n"; // 4
    print_ll(h7);
    cout << (get_mid_point_of_linked_list(h7))->data << "\n\n"; // 2
    print_ll(h8);
    cout << (get_mid_point_of_linked_list(h8))->data << "\n\n"; // 21

    cout << "\nOptimised\n";
    print_ll(h1);
    cout << (get_mid_point_of_linked_list_v2_optimised(h1))->data << "\n\n"; // 3
    print_ll(h2);
    cout << (get_mid_point_of_linked_list_v2_optimised(h2))->data << "\n\n"; // 25
    print_ll(h3);
    cout << (get_mid_point_of_linked_list_v2_optimised(h3))->data << "\n\n"; // 15
    print_ll(h4);
    cout << (get_mid_point_of_linked_list_v2_optimised(h4))->data << "\n\n"; // 17
    print_ll(h5);
    cout << (get_mid_point_of_linked_list_v2_optimised(h5))->data << "\n\n"; // 5
    print_ll(h6);
    cout << (get_mid_point_of_linked_list_v2_optimised(h6))->data << "\n\n"; // 4
    print_ll(h7);
    cout << (get_mid_point_of_linked_list_v2_optimised(h7))->data << "\n\n"; // 2
    print_ll(h8);
    cout << (get_mid_point_of_linked_list_v2_optimised(h8))->data << "\n\n"; // 21

    return 0;
}