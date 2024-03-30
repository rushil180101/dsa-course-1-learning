#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Pet {
public:
    string name, type;
    Pet(string name, string type)
    {
        this->name = name;
        this->type = type;
    }
    void display()
    {
        cout << "Pet - Type = " << this->type << ", Name = " << this->name << endl;
    }
};

class Human {
public:
    string name;
    Pet *p;
    Human(string name, Pet *p)
    {
        this->name = name;
        // this->p = p; // Shallow copy

        // Deep copy
        this->p = new Pet(p->name, p->type);
    }
    void display()
    {
        cout << "Human - Name = " << this->name << " | ";
        this->p->display();
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Pet p1("Tuffy", "Dog");

    Human h1("H1", &p1);
    h1.display();

    Human h2("H2", &p1);
    h2.display();

    h2.p->name = "Guffy";
    // If shallow copied, changing name here in h2 also affects in h1
    cout << "\n\nAfter change\n\n";
    h1.display();
    h2.display();

    cout << "\n\n--------------------\n\n";
    cout << "\n\nDeep copy\n\n";
    Pet *p2 = new Pet("Sqweak", "Parrot");
    Human h3("H3", p2), h4("H4", p2);
    h3.display();
    h4.display();

    h4.p->name = "Popat";

    cout << "\n\nAfter change\n\n";
    h3.display();
    h4.display();

    return 0;
}
