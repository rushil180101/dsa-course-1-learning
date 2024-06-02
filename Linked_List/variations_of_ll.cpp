#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////////////

// Singly Linked List
class SinglyLLNode
{
public:
    int data;
    SinglyLLNode *next;

    SinglyLLNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

SinglyLLNode* take_singly_ll_input()
{
    int data;
    cin >> data;

    SinglyLLNode *head = NULL;
    SinglyLLNode *temp = NULL;
    while (data != -1)
    {
        SinglyLLNode *n = new SinglyLLNode(data);
        if (temp == NULL)
        {
            head = n;
            temp = n;
        }
        else
        {
            temp->next = n;
            temp = n;
        }
        cin >> data;
    }
    return head;
}

void print_singly_ll(SinglyLLNode *head)
{
    while (head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

////////////////////////////////////////////////////////////////////////

// Doubly Linked List
class DoublyLLNode
{
public:
    int data;
    DoublyLLNode *prev;
    DoublyLLNode *next;

    DoublyLLNode(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

DoublyLLNode* take_doubly_ll_input()
{
    int data;
    cin >> data;

    DoublyLLNode *head = NULL;
    DoublyLLNode *temp = NULL;

    while (data != -1)
    {
        DoublyLLNode *n = new DoublyLLNode(data);
        if (temp == NULL)
        {
            head = n;
            temp = n;
        }
        else
        {
            temp->next = n;
            n->prev = temp;
            temp = n;
        }
        cin >> data;
    }
    return head;
}

void print_doubly_ll(DoublyLLNode *head)
{
    while (head)
    {
        cout << "(";
        cout << head->prev << "|";
        cout << head->data << "|";
        cout << head->next << ")";
        cout << "<--->";
        
        head = head->next;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////

// Circular Singly Linked List
class CircularSinglyLLNode
{
public:
    int data;
    CircularSinglyLLNode *next;

    CircularSinglyLLNode(int data)
    {
        this->data = data;
        this->next = this;
    }
};

CircularSinglyLLNode* take_circular_singly_ll_input()
{
    int data;
    cin >> data;

    CircularSinglyLLNode *head = NULL;
    CircularSinglyLLNode *temp = NULL;

    while (data != -1)
    {
        CircularSinglyLLNode *n = new CircularSinglyLLNode(data);
        if (temp == NULL)
        {
            head = n;
            temp = n;
            n->next = head;
        }
        else
        {
            temp->next = n;
            n->next = head;
            temp = n;
        }
        cin >> data;
    }
    return head;    
}

void print_circular_singly_ll(CircularSinglyLLNode *head)
{
    CircularSinglyLLNode * temp = head;
    while (temp->next != head)
    {
        cout << "(" << temp->data << "|" << temp->next << ")--->";
        temp = temp->next;
    }
    cout << "(" << temp->data << "|" << temp->next << ")--->";
    cout << endl;
}

////////////////////////////////////////////////////////////////////////

// Circular Doubly Linked List
class CircularDoublyLLNode
{
public:
    int data;
    CircularDoublyLLNode *prev;
    CircularDoublyLLNode *next;

    CircularDoublyLLNode(int data)
    {
        this->data = data;
        this->prev = this;
        this->next = this;
    }
};

CircularDoublyLLNode* take_circular_doubly_ll_input()
{
    int data;
    cin >> data;

    CircularDoublyLLNode *head = NULL;
    CircularDoublyLLNode *temp = NULL;

    while (data != -1)
    {
        CircularDoublyLLNode *n = new CircularDoublyLLNode(data);
        if (temp == NULL)
        {
            head = n;
            temp = n;
        }
        else
        {
            temp->next = n;
            n->prev = temp;

            n->next = head;
            head->prev = n;

            temp = n;
        }
        cin >> data;
    }
    return head;
}

void print_circular_doubly_ll(CircularDoublyLLNode *head)
{
    CircularDoublyLLNode *temp = head;
    while (temp->next != head)
    {
        cout << "(";
        cout << temp->prev << "|";
        cout << temp->data << "|";
        cout << temp->next << ")";
        cout << "<--->";
        
        temp = temp->next;
    }
    cout << "(";
    cout << temp->prev << "|";
    cout << temp->data << "|";
    cout << temp->next << ")";
    cout << "<--->";
    cout << endl;
}

////////////////////////////////////////////////////////////////////////

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    SinglyLLNode *sll1 = take_singly_ll_input();
    print_singly_ll(sll1);
    cout << endl;

    DoublyLLNode *dll1 = take_doubly_ll_input();
    print_doubly_ll(dll1);
    cout << endl;

    CircularSinglyLLNode *csll1 = take_circular_singly_ll_input();
    print_circular_singly_ll(csll1);
    cout << endl;

    CircularDoublyLLNode *cdll1 = take_circular_doubly_ll_input();
    print_circular_doubly_ll(cdll1);
    cout << endl;

    return 0;
}