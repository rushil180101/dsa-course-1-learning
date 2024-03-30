#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    int account_id;
    string account_type;

    // Static data member for class level access
    static float interest_rate;

    Account(int account_id, string account_type)
    {
        this->account_id = account_id;
        this->account_type = account_type;
    }

    // Static function (Can only access static data members and other static functions)
    static float get_interest_rate() { return interest_rate; }
};
// Initializing static members outside the class
float Account::interest_rate = 7.5;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    Account a1(1, "Savings"), a2(2, "Current");

    cout << a1.account_id << " " << a1.account_type << " " << a1.interest_rate << endl;
    cout << a2.account_id << " " << a2.account_type << " " << a2.interest_rate << endl;
    cout << Account::interest_rate << endl;

    a2.interest_rate = 5.5;
    cout << a1.account_id << " " << a1.account_type << " " << a1.interest_rate << endl;
    cout << a2.account_id << " " << a2.account_type << " " << a2.interest_rate << endl;
    cout << Account::interest_rate << endl;

    Account::interest_rate = 6.3;
    cout << a1.account_id << " " << a1.account_type << " " << a1.interest_rate << endl;
    cout << a2.account_id << " " << a2.account_type << " " << a2.interest_rate << endl;
    cout << Account::interest_rate << endl;

    // Calling static function using class name or object
    cout << "Calling static function using class name or object" << endl;
    cout << Account::get_interest_rate() << endl;
    cout << a1.get_interest_rate() << endl;
    cout << a2.get_interest_rate() << endl;

    return 0;
}
