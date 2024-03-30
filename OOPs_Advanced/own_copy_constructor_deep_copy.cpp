#include <iostream>
using namespace std;

class A {
public:
    int x;
    int *arr;
    A(int x, int *arr)
    {
        this->x = x;
        // this->arr = arr; // Shallow copy

        // Deep copy
        int *temp = new int [this->x];
        for (int i=0; i<x; i++)
        {
            temp[i] = arr[i];
        }
        this->arr = temp;
    }

    // Own copy constructor using deep copy (Approach 1)
    /*
    A(A &obj)
    {
        A *temp = new A(obj.x, obj.arr);
        this->x = temp->x;
        this->arr = temp->arr;
    }
    */

    // Own copy constructor using deep copy (Approach 2)
    A(A &obj)
    {
        this->x = obj.x;
        // Deep copy
        this->arr = new int [this->x];
        // Copy the values in array
        for (int i=0; i<this->x; i++)
        {
            this->arr[i] = obj.arr[i];
        }
    }

    void display()
    {
        cout << this->x << " | ";
        for (int i=0; i<x; i++)
        {
            cout << this->arr[i] << "  ";
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

    int arr[] = {1, 2, 3, 4, 5};
    A obj1(5, arr);
    obj1.display();

    A obj2(obj1); // Default copy constructor called
    obj2.display();

    cout << "\n\nChanged array in main program\n\n";
    arr[2] = 75;
    obj1.display();
    obj2.display();

    cout << "\n\nChanged array in one object\n\n";
    obj1.arr[0] = 95;
    obj1.display();
    obj2.display();

    return 0;
}
