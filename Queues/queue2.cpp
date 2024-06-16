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

// queue implementation using linked list
template <class T>
class Queue
{
public:
    int q_size;
    Node<T> *head;
    Node<T> *tail;

    Queue()
    {
        this->q_size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void push(T data)
    {
        // Insert at tail
        Node<T> *n = new Node<T>(data);
        if (this->tail)
        {
            tail->next = n;
            tail = n;
        }
        else
        {
            head = n;
            tail = n;
        }
        this->q_size++;
    }

    void pop()
    {
        // Remove from head
        if (this->head)
        {
            Node<T> *temp = head;
            if (this->head == this->tail)
            {
                this->head = NULL;
                this->tail = NULL;
            }
            else
            {
                this->head = this->head->next;
            }
            temp->next = NULL;
            delete temp;
            this->q_size--;
        }
        else
        {
            cout << "cannot pop, q is empty" << endl;
        }
    }

    T front()
    {
        if (this->head)
        {
            return this->head->data;
        }
        cout << "no data, q is empty" << endl;
        return 0;
    }

    int get_size()
    {
        return this->q_size;
    }

    bool is_empty()
    {
        return (this->q_size == 0);
    }

    void print_q()
    {
        Node<T> *iter = this->head;
        while (iter)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }
        cout << endl;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Queue<int> q1;
    Queue<char> q2;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    q1.push(60);
    q1.push(70);
    q1.push(80);
    q1.print_q(); // 10 to 80

    cout << q1.front() << endl; // 10
    q1.pop();
    cout << q1.front() << endl; // 20
    q1.pop();
    cout << q1.front() << endl; // 30
    q1.pop();
    cout << q1.front() << endl; // 40
    q1.pop();
    cout << q1.front() << endl; // 50
    q1.pop();
    cout << q1.front() << endl; // 60
    q1.pop();
    cout << q1.front() << endl; // 70

    q1.print_q(); // 70 80
    cout << q1.get_size() << endl; // 2
    q1.pop();
    cout << q1.front() << endl; // 80
    q1.print_q(); // 80
    cout << q1.get_size() << endl; // 1
    cout << q1.is_empty() << endl; // 0

    q1.pop();
    cout << q1.front() << endl; // cannot get front, q empty
    q1.pop(); // cannot pop, q empty

    cout << q1.get_size() << endl; // 0
    cout << q1.is_empty() << endl; // 1
    q1.print_q(); // no output

    return 0;
}