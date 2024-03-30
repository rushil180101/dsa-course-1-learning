#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A(int a)
    {
        this->a = a;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    A obj1(20); // Parameterized constructor called
    A obj2(obj1); // Default copy constructor called

    A *obj3 = new A(obj1); // Default copy constructor called

    cout << "obj1 - " << obj1.a << endl;
    cout << "obj2 - " << obj2.a << endl;
    cout << "*obj3 - " << obj3->a << endl;

    A obj4(7), obj5(10);
    obj5 = obj4; // Copy assignment operator called
    cout << obj5.a << endl;

    return 0;
}
