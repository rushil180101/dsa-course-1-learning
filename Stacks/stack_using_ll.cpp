#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <class T>
class Stack
{
public:
    Node<T> *head;
    int size;

    Stack()
    {
        this->head = NULL;
        this->size = 0;
    }

    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        if (this->head == NULL)
        {
            this->head = n;
            this->size++;
        }
        else
        {
            Node<T> *temp = this->head;
            this->head = n;
            this->head->next = temp;
            this->size++;
        }
    }

    void pop()
    {
        if (this->head)
        {
            Node<T> *temp = this->head;
            this->head = this->head->next;
            
            temp->next = NULL;
            delete temp;

            this->size--;
        }
    }

    T top()
    {
        if (this->head)
        {
            return this->head->data;
        }
        return 0;
    }

    int get_size()
    {
        return this->size;
    }

    bool is_empty()
    {
        return (this->size == 0);
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << s1.top() << endl; // 50
    s1.pop();

    cout << s1.top() << endl; // 40
    s1.pop();

    cout << s1.top() << endl; // 30
    s1.pop();

    cout << s1.get_size() << endl; // 2
    cout << s1.is_empty() << endl; // 0

    cout << s1.top() << endl; // 20
    s1.pop();

    cout << s1.top() << endl; // 10
    s1.pop();

    cout << s1.get_size() << endl; // 0
    cout << s1.is_empty() << endl; // 1

    return 0;
}