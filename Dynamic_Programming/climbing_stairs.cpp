#include <bits/stdc++.h>
using namespace std;

/*
Climbing stairs problem
Find the number of ways to climb n stairs
In each step, you can take a jump of either 1 stair or 2 stairs
*/
int get_number_of_ways_to_climb_n_stairs(int n)
{
    // Iterative approach - Bottom up DP
    int *dp = new int [n+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    int ans = dp[n];
    delete []dp;
    return ans;
}

/*
DP climbing stairs generalised
Find the number of ways to climb n stairs
In each step, you can take a jump of max k stairs
*/
int climbing_stairs_dp_generalised(int n, int k)
{
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=n; i++)
    {
        int s = 0;
        for (int j=i-1; j>=i-k; j--)
        {
            s += dp[j];
        }
        dp[i] = s;
    }
    return dp[n];
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int n, k;

    n = 6;
    cout << n << " --> " << get_number_of_ways_to_climb_n_stairs(n) << endl;
    k = 2;
    cout << n << ", " << k << " --> " << climbing_stairs_dp_generalised(n, k) << endl;
    k = 3;
    cout << n << ", " << k << " --> " << climbing_stairs_dp_generalised(n, k) << endl;


    return 0;
}