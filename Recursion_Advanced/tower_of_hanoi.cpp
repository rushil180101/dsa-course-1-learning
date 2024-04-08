#include <bits/stdc++.h>
using namespace std;

int tower_of_hanoi_steps(int disks)
{
    if (disks <= 1)
    {
        return 1;
    }
    return 1 + (2 * tower_of_hanoi_steps(disks - 1));

    /*
    Logic
    E.g. there are 4 disks and 3 pillars A B C
    -> First move top 3 disks from A to B (recursion)
    -> Then move last disk from A to C (1 step)
    -> Then move 3 disks from B to C (recursion)
    */
}

void steps_in_tower_of_hanoi(
    int n,
    char source='A',
    char helper='B',
    char destination='C'
)
{
    if (n <= 0)
    {
        return;
    }
    steps_in_tower_of_hanoi(n-1, source, destination, helper);
    cout << "Moving disk " << n << " from " << source << " -- to --> " << destination << endl;
    steps_in_tower_of_hanoi(n-1, helper, source, destination);
}

int main()
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int disks;
    disks = 1;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 1
    disks = 3;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 7
    disks = 4;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 15
    disks = 10;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 1023
    disks = 7;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 127
    disks = 8;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 255
    disks = 13;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 8191
    disks = 6;
    cout << "Disks = " << disks << ", Steps = " << tower_of_hanoi_steps(disks) << endl; // 63

    cout << "\n\nSteps in TOH\n\n";
    disks = 3;
    steps_in_tower_of_hanoi(disks);
    return 0;
}