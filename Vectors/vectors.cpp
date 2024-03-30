#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Vector properties
1. We do not need to provide the size upfront
2. Vector scales dynamically - Doubles its size upon reaching full capacity
*/

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<int> v1; // Static vector creation - Memory gets deleted automatically
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> *vp1 = new vector<int>(); // Dynamic vector creation - Need to delete manually
    vp1->push_back(4);
    vp1->push_back(5);
    vp1->push_back(6);

    for (int i=0; i<3; i++)
    {
        cout << v1.at(i) << ", " << vp1->at(i) << endl;
    }

    // Inserting elements
    cout << endl << "Inserting elements" << endl;
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    // We can use box brackets [] to update and insert elements in a vector
    v2[1] = 10;
    v2[5] = 100;
    for (int i=0; i<7; i++)
    {
        cout << v2[i] << endl;
    }
    // Never use box brackets [] to insert elements in vector - It does not increase vector size
    // Always use push_back() function

    // Accessing elements
    cout << endl << "Accessing elements" << endl;
    // Vector elements can be accessed using box brackets [] as well as at() function
    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);

    cout << v3[2] << endl;
    cout << v3.at(2) << endl;

    cout << v3[5] << endl; // Invalid index - Still it will execute and provide garbage value
    // cout << v3.at(5) << endl; // Invalid index - at() function will check and generate error
    // Try to use at() function instead of box brackets to access vector elements

    // Pop elements from last
    cout << "Size = " << v3.size() << endl;
    v3.pop_back();
    cout << "Size = " << v3.size() << endl;

    // Size vs Capacity
    cout << endl << "Size vs Capacity" << endl;
    vector<int> v4;
    v4.push_back(10);
    v4.push_back(20);
    v4.push_back(30);
    cout << "Size = " << v4.size() << endl;
    cout << "Capacity = " << v4.capacity() << endl;

    v4.push_back(50);
    cout << "Size = " << v4.size() << endl;
    cout << "Capacity = " << v4.capacity() << endl;

    v4.push_back(60);
    cout << "Size = " << v4.size() << endl;
    cout << "Capacity = " << v4.capacity() << endl;

    // Sorting a vector
    cout << endl << "Sorting a vector using sort()" << endl;
    vector<int> v5;
    v5.push_back(76);
    v5.push_back(36);
    v5.push_back(93);
    v5.push_back(15);
    v5.push_back(75);
    for (int i=0; i<v5.size(); i++) { cout << v5.at(i) << ", "; }
    sort(v5.begin(), v5.end());
    cout << endl << "Sorted" << endl;
    for (int i=0; i<v5.size(); i++) { cout << v5.at(i) << ", "; }

    return 0;
}
