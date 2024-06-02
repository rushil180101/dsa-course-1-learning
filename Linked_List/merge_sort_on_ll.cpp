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

////////////////////////////////////////////////////////////////////

Node* get_mid_point_of_ll(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow_ptr = head;
    Node *fast_ptr = head->next;
    while (fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    if (fast_ptr)
        return slow_ptr->next;
    return slow_ptr;
}

Node* merge_2_sorted_linked_lists_recursive(Node *head1, Node *head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data <= head2->data)
    {
        head1->next = merge_2_sorted_linked_lists_recursive(head1->next, head2);
        return head1;
    }

    head2->next = merge_2_sorted_linked_lists_recursive(head1, head2->next);
    return head2;
}

// Merge sort
// 1. Divide into two halves
// 2. Apply recursive merge sort on both halves
// 3. Merge two sorted halves into one
Node* merge_sort_on_linked_list(Node *head)
{
    if (head == NULL) return NULL;

    // Base case - Return if only one element is present
    if (head->next == NULL)
    {
        return head;
    }

    Node *temp_head = head;
    // Divide into two halves
    Node *mid_point_of_ll = get_mid_point_of_ll(temp_head);
    Node *first_half_head = head;
    while (temp_head->next != mid_point_of_ll)
    {
        temp_head = temp_head->next;
    }
    temp_head->next = NULL;
    Node *secnd_half_head = mid_point_of_ll;

    // Apply recursive merge sort on both halves
    Node *sorted_first_half = merge_sort_on_linked_list(first_half_head);
    Node *sorted_secnd_half = merge_sort_on_linked_list(secnd_half_head);

    // Merge two sorted halves into one
    Node *fh = merge_2_sorted_linked_lists_recursive(sorted_first_half, sorted_secnd_half);
    return fh;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Node *ll, *sorted_ll;
    for (int i=0; i<10; i++)
    {
        ll = take_ll_input();
        print_ll(ll);
        sorted_ll = merge_sort_on_linked_list(ll);
        print_ll(sorted_ll);
        cout << endl;
    }

    return 0;
}
