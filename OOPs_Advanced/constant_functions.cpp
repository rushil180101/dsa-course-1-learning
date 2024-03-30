#include <iostream>
using namespace std;

class Complex {
public:
    int r, i;
    Complex(int r, int i)
    {
        this->r = r;
        this->i = i;
    }

    // Constant functions can be called by const objects
    int get_real() const { return this->r; }
    int get_img() const { return this->i; }

    void set_real(int r) { this->r = r; }
    void set_img(int i) { this->i = i; }

    void display() const
    {
        cout << this->r << " + " << this->i << "i" << endl;
    }
};

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    const Complex c1(5, 4);
    c1.display();

    return 0;
}
