#include <iostream>
using namespace std;

class Employee
{
public:
    int emp_id;
    string name;

    // Constructor
    Employee()
    {
        cout << "Basic constructor called" << endl;
    }

    Employee(int emp_id, string name)
    {
        cout << "Parameterized constructor called" << endl;
        this->emp_id = emp_id;
        this->name = name;
    }

    // Getters and setters
    void set_attribs(int emp_id, string name)
    {
        this->emp_id = emp_id;
        this->name = name;
    }
    void get_attribs()
    {
        cout << "Emp ID   = " << this->emp_id << endl;
        cout << "Emp Name = " << this->name << endl;
    }
};

class Test
{
    int a;
public:
    Test(int a=5)
    {
        this->a = a;
    }
    int get_a()
    {
        return this->a;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    // Static object creation
    Employee e1;
    e1.emp_id = 1;
    e1.name = "Emp1";
    e1.get_attribs();

    // Dynamic object creation
    Employee *e2 = new Employee;
    (*e2).emp_id = 2;
    e2->name = "Emp2";
    e2->get_attribs();

    Employee e3(3, "Emp3");
    e3.set_attribs(3, "Employee3");
    e3.get_attribs();

    Test t1, t2(-10);
    cout << t1.get_a() << endl;
    cout << t2.get_a() << endl;

    return 0;
}
