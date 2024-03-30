#include <iostream>
using namespace std;

class DynamicArray {
public:
    int *arr;
    int size, next_idx = 0;

    DynamicArray(int size)
    {
        this->size = size;
        this->arr = new int [this->size];
    }

    // Copy constructor for deep copy
    DynamicArray(DynamicArray &d)
    {
        this->size = d.size;
        this->next_idx = d.next_idx;
        this->arr = new int [d.size];
        for (int i=0; i<d.size; i++)
        {
            this->arr[i] = d.arr[i];
        }
    }

    void display()
    {
        cout << "Size = " << this->size << " | ";
        for (int i=0; i<this->size; i++)
        {
            cout << this->arr[i] << "   ";
        }
        cout << endl;
    }

    void add_element(int element)
    {
        if (this->next_idx == this->size)
        {
            this->size *= 2;
            int *temp = new int [this->size];
            for (int i=0; i<this->size/2; i++)
            {
                temp[i] = this->arr[i];
            }
            delete []this->arr;
            // If we do not delete the previous array, it can cause memory leak
            this->arr = temp;
        }
        this->arr[this->next_idx] = element;
        this->next_idx += 1;
    }

    void add_element_at_idx(int idx, int element)
    {
        if (idx < this->next_idx)
        {
            this->arr[idx] = element;
        }
        else if (idx == this->next_idx)
        {
            this->add_element(element);
        }
        else
        {
            return;
        }
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    DynamicArray d1(5);
    d1.add_element(1);
    d1.add_element(2);
    d1.add_element(3);
    d1.add_element(4);
    d1.add_element(5);

    d1.display(); // 5 | 1 to 5

    d1.add_element(6);
    d1.add_element(7);
    d1.add_element(8);
    d1.add_element(9);
    d1.add_element(10);

    d1.display(); // 10 | 1 to 10

    d1.add_element(11);
    d1.add_element(12);

    d1.display(); // 20 | 1 to 12 + 8 garbage values

    d1.add_element_at_idx(1, 20);
    d1.add_element_at_idx(8, 90);
    d1.add_element_at_idx(12, 13);

    d1.display();
    cout << endl;

    // Shallow copy and deep copy
    DynamicArray d2(4);
    d2.add_element(1);
    d2.add_element(1);
    d2.add_element(1);
    d2.add_element(1);

    DynamicArray d3(d2);

    d2.display();
    d3.display();

    d2.add_element_at_idx(1, 55);
    d2.display();
    d3.display();

    cout << endl;
    d3.add_element(23);
    d3.add_element(24);
    d2.display();
    d3.display();
    return 0;
}
