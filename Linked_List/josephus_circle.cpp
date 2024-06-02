#include <bits/stdc++.h>
using namespace std;

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

int get_safe_position(int n, int m, CircularSinglyLLNode *head)
{
    CircularSinglyLLNode *temp = head;
    while (temp->data != temp->next->data)
    {
        for (int i=1; i<m-1; i++)
        {
            temp = temp->next;
        }

        CircularSinglyLLNode *x = temp->next;
        temp->next = temp->next->next;

        x->next = NULL;
        delete x;

        temp = temp->next;
    }
    return temp->data;    
}

int main() 
{
    // ########################## //
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    int n, m;
    cin >> n >> m;

    // Create circular singly ll
    CircularSinglyLLNode *head = NULL;
    CircularSinglyLLNode *temp = NULL;
    for (int i=1; i<=n; i++)
    {
        CircularSinglyLLNode *n = new CircularSinglyLLNode(i);
        if (temp == NULL)
        {
            head = n;
            temp = n;
        }
        else
        {
            temp->next = n;
            n->next = head;
            temp = n;
        }
    }

    int ans = get_safe_position(n, m, head);
    cout << ans << endl;

    return 0;
}