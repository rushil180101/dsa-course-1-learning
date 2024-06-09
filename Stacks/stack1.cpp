#include <bits/stdc++.h>
using namespace std;

// Stack using array
class Stack
{
    int *arr;
    int next_idx;
    int capacity;

public:
    Stack(int capacity=5)
    {
        this->capacity = capacity;
        this->arr = new int [this->capacity];
        this->next_idx = 0;
    }

    int size()
    {
        return this->next_idx;
    }

    bool is_empty()
    {
        return this->next_idx == 0;
    }

    bool is_full()
    {
        return this->next_idx == this->capacity;
    }

    void push(int data)
    {
        if (!(this->is_full()))
        {
            this->arr[this->next_idx] = data;
            (this->next_idx)++;
        }
    }

    void pop()
    {
        if (!(this->is_empty()))
        {
            (this->next_idx)--;
        }
    }

    int top()
    {
        if (!(this->is_empty()))
        {
            int data = this->arr[(this->next_idx)-1];
            return data;
        }
        return -1;
    }
};

int main() 
{
    // ########################## //
    // freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ########################## //

    Stack *s1 = new Stack(5);
    s1->push(1);
    s1->push(2);
    s1->push(3);
    s1->push(4);

    cout << s1->top() << endl;

    s1->pop();
    cout << s1->top() << endl;
    s1->pop();
    cout << s1->top() << endl;

    cout << s1->size() << endl;

    cout << "\n\n";

    Stack s2(4);
    s2.push(10);
    s2.push(20);
    s2.push(30);
    s2.push(40);
    s2.push(50);

    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
    s2.pop();

    cout << s2.size() << endl;
    cout << s2.is_empty() << endl;

    return 0;
}