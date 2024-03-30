#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    const int emp_id;
    string name;
    int age;
    int &magic_number;

    // Use initialization list to initialize data members that are
    // constant variables or reference variables
    Employee(int emp_id, string name, int age, int magic_number) : emp_id(emp_id), magic_number(magic_number)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "Id = " << this->emp_id << endl;
        cout << "Name = " << this->name << endl;
        cout << "Age = " << this->age << endl;
        cout << "Magic number = " << this->magic_number << endl;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    // const int x; // --> Error : uninitialized const 'x'
    // int &a; // Error --> reference variable 'a' declared but not initialized

    // Solution --> Use initialization list

    Employee e1(1, "Emp1", 23, 14), e2(2, "Emp2", 25, 27);
    e1.display();
    cout << endl;
    e2.display();

    return 0;
}
