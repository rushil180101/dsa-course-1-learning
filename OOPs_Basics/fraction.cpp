#include <iostream>
using namespace std;

int get_hcf(int a, int b)
{
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}

class Fraction
{
private:
    int numerator, denominator;
public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // Getters
    int get_numerator() { return this->numerator; }
    int get_denominator() { return this->denominator; }
    // Setters
    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denominator(int denominator)
    {
        this->denominator = denominator;
    }

    void print()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    void add(Fraction &f)
    {
        int n = (this->numerator * f.get_denominator()) + (f.get_numerator() * this->denominator);
        int d = this->denominator * f.get_denominator();
        int hcf = get_hcf(n, d);
        this->numerator = n / hcf;
        this->denominator = d / hcf;
    }

    void multiply(Fraction &f)
    {
        int n = this->numerator * f.get_numerator();
        int d = this->denominator * f.get_denominator();
        int hcf = get_hcf(n, d);
        this->numerator = n / hcf;
        this->denominator = d / hcf;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Fraction f1(3, 7), f2(5, 4), f3(10, 1), f4(37, 23);
    f1.print();
    f2.print();
    f3.print();
    f4.print();

    cout << "Adding" << endl;
    f1.add(f3);
    f4.add(f2);
    f1.print();
    f2.print();
    f3.print();
    f4.print();

    cout << "Multiplying" << endl;
    f3.multiply(f2);
    f3.print();

    return 0;
}
