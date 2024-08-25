#include <bits/stdc++.h>
using namespace std;

/*
0-1 Knapsack
Given a knapsack of some capacity X kg
and given an array of items with their weights and prices respectively
Find the maximum profit that can be generated by putting items in the knapsack
e.g.
knapsack capacity = 10 kg
items   = item1 item2 item3 item4
weights = 4 kg  3 kg  5 kg  15 kg
prices  = 25    10    20    60
*/

int get_max_profit_from_knapsack_recursive(
    int knapsack_capacity,
    int n,
    int *weights,
    int *prices,
    int i=0,
    int max_profit=0,
    bool perform_sort=true
)
{
    if (perform_sort)
    {
        for (int round=1; round<n; round++)
        {
            bool swapped = false;
            for (int k=0; k<n-round; k++)
            {
                if (prices[k]<prices[k+1])
                {
                    swap(prices[k], prices[k+1]);
                    swap(weights[k], weights[k+1]);
                    swapped = true;
                }
            }
            if (!swapped)
            {
                break;
            }
        }
    }
    perform_sort = false;

    if (i>=n)
    {
        return max_profit;
    }

    if (weights[i]<=knapsack_capacity)
    {
        knapsack_capacity -= weights[i];
        max_profit += prices[i];
    }
    max_profit = get_max_profit_from_knapsack_recursive(
        knapsack_capacity,
        n,
        weights,
        prices,
        i+1,
        max_profit,
        perform_sort
    );
    return max_profit;
}

int get_max_profit_from_knapsack_recursive_v2(
    int knapsack_capacity,
    int n,
    int *weights,
    int *prices,
    int i=0
)
{
    if (i>=n || knapsack_capacity<=0)
    {
        return 0;
    }

    if (weights[i]>knapsack_capacity)
    {
        return get_max_profit_from_knapsack_recursive_v2(
            knapsack_capacity,
            n,
            weights,
            prices,
            i+1
        );
    }

    /*
    Get max profit by either
    1. including the item in knapsack
    OR
    2. excluding the item from knapsack
    */
    int max_profit_by_including_item_i = prices[i] + get_max_profit_from_knapsack_recursive_v2(
        knapsack_capacity-weights[i],
        n,
        weights,
        prices,
        i+1
    );
    int max_profit_by_excluding_item_i = get_max_profit_from_knapsack_recursive_v2(
        knapsack_capacity,
        n,
        weights,
        prices,
        i+1
    );

    int total_max_profit = max(
        max_profit_by_including_item_i,
        max_profit_by_excluding_item_i
    );
    return total_max_profit;
}

// 0-1 knapsack DP
int get_max_profit_from_knapsack_dp(
    int knapsack_capacity,
    int n,
    int *weights,
    int *prices
)
{
    int dp[n+1][knapsack_capacity+1];

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=knapsack_capacity; j++)
        {
            if (i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if (weights[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                int excl = dp[i-1][j];
                int incl = prices[i-1] + dp[i-1][j-weights[i-1]];
                int ans = max(excl, incl);
                dp[i][j] = ans;
            }
        }
    }
    return dp[n][knapsack_capacity];
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {4, 3, 5, 15};
        int prices[n] = {25, 10, 20, 60};
        int ans = get_max_profit_from_knapsack_recursive(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 5;
        int n = 4;
        int weights[n] = {1, 2, 4, 5};
        int prices[n] = {5, 4, 8, 6};
        int ans = get_max_profit_from_knapsack_recursive(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {2, 1, 5, 3};
        int prices[n] = {300, 200, 400, 500};
        int ans = get_max_profit_from_knapsack_recursive(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    cout << "\n\n=============================\n\n";

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {4, 3, 5, 15};
        int prices[n] = {25, 10, 20, 60};
        int ans = get_max_profit_from_knapsack_recursive_v2(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 5;
        int n = 4;
        int weights[n] = {1, 2, 4, 5};
        int prices[n] = {5, 4, 8, 6};
        int ans = get_max_profit_from_knapsack_recursive_v2(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {2, 1, 5, 3};
        int prices[n] = {300, 200, 400, 500};
        int ans = get_max_profit_from_knapsack_recursive_v2(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 50;
        int n = 3;
        int weights[n] = {10, 20, 30};
        int prices[n] = {60, 100, 120};
        int ans = get_max_profit_from_knapsack_recursive_v2(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {12, 13, 15, 19};
        int prices[n] = {10, 20, 30, 40};
        int ans = get_max_profit_from_knapsack_recursive_v2(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    cout << "\n\n=============================\nDP\n\n";

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {4, 3, 5, 15};
        int prices[n] = {25, 10, 20, 60};
        int ans = get_max_profit_from_knapsack_dp(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 5;
        int n = 4;
        int weights[n] = {1, 2, 4, 5};
        int prices[n] = {5, 4, 8, 6};
        int ans = get_max_profit_from_knapsack_dp(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {2, 1, 5, 3};
        int prices[n] = {300, 200, 400, 500};
        int ans = get_max_profit_from_knapsack_dp(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 50;
        int n = 3;
        int weights[n] = {10, 20, 30};
        int prices[n] = {60, 100, 120};
        int ans = get_max_profit_from_knapsack_dp(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    {
        int knapsack_capacity = 10;
        int n = 4;
        int weights[n] = {12, 13, 15, 19};
        int prices[n] = {10, 20, 30, 40};
        int ans = get_max_profit_from_knapsack_dp(
            knapsack_capacity,
            n,
            weights,
            prices
        );
        cout << ans << endl;
    }

    return 0;
}