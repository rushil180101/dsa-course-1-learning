#include <bits/stdc++.h>
using namespace std;

// queue implementation using array
template <class T>
class Queue
{
public:
    T *arr;
    int f_idx; // front index
    int n_idx; // next  index
    int capacity;
    int size;

    Queue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;

        this->arr = new T [this->capacity];
        this->f_idx = -1;
        this->n_idx = 0;
    }

    void push(T data)
    {
        if (this->size < this->capacity)
        {
            this->arr[this->n_idx] = data;
            this->n_idx = ++(this->n_idx) % this->capacity;
            this->size++;

            if (this->f_idx == -1)
            {
                this->f_idx++;
            }
        }
        else
        {
            cout << "queue full, cannot push data = " << data << endl;
        }
    }

    void pop()
    {
        if (!(is_empty()))
        {
            this->f_idx = ++(this->f_idx) % (this->capacity);
            this->size--;
        }
        else
        {
            this->f_idx = -1;
            this->n_idx = 0;
            cout << "queue empty, cannot pop data" << endl;
        }
    }

    T front()
    {
        if (!(is_empty()))
        {
            return this->arr[this->f_idx];
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

    void print_q()
    {
        if (!(is_empty()))
        {
            int i = this->f_idx;
            for (int k=0; k<this->size; k++)
            {
                cout << this->arr[i] << " ";
                i = (++i) % this->capacity;
            }
            cout << endl;
        }
        else
        {
            cout << "queue empty" << endl;
        }
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Queue<int> q1(5);
    Queue<char> q2(5);

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    q1.push(60); // q full
    cout << q1.get_size() << endl; // 5
    cout << q1.front() << endl; // 10
    q1.pop();
    cout << q1.front() << endl; // 20
    q1.pop();
    q1.print_q(); // 30 40 50
    cout << q1.get_size() << endl; // 3

    cout << q1.front() << endl; // 30
    q1.pop();
    cout << q1.front() << endl; // 40
    q1.pop();
    cout << q1.front() << endl; // 50
    q1.pop();
    q1.pop(); // q empty
    cout << q1.get_size() << endl; // 0


    cout << "\n--------------\n";

    q2.push('a');
    q2.push('b');
    q2.push('c');
    q2.push('d');
    q2.push('e');
    q2.print_q(); // a b c d e
    cout << q2.get_size() << endl; // 5
    q2.push('f'); // q full
    cout << q2.get_size() << endl; // 5

    cout << q2.front() << endl; // a
    q2.pop();
    cout << q2.front() << endl; // b
    q2.pop();
    cout << q2.get_size() << endl; // 3

    q2.push('f');
    cout << q2.get_size() << endl; // 4
    q2.push('f');
    cout << q2.get_size() << endl; // 5
    q2.print_q(); // c d e f f

    return 0;
}