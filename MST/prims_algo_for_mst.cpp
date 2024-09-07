#include <bits/stdc++.h>
using namespace std;


int get_min_idx(vector<int> &weight, vector<bool> &visited)
{
    int min_idx = weight.size();
    int min_value = INT_MAX;
    for (int i=0; i<weight.size(); i++)
    {
        if (weight[i]<min_value && visited[i]==false)
        {
            min_value = weight[i];
            min_idx = i;
        }
    }
    return min_idx;
}

/*
WIP - Prims algorithm for finding minimum spanning tree
*/
int get_minimum_spanning_tree_cost_prims_algo(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> weight(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    weight[0] = 0;
    int ans = 0;

    for (int count=0; count<n; count++)
    {
        int u = get_min_idx(weight, visited);
        visited[u] = true;

        for (int v=0; v<n; v++)
        {
            if (visited[v]==false)
            {
                if (graph[u][v]<weight[v])
                {
                    weight[v] = graph[u][v];
                    parent[v] = u;
                    ans += weight[v];
                }
            }
        }
    }

    return ans;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<vector<int>> graph1 = {
        {0, 4, 8, 0, 0},
        {4, 0, 2, 6, 0},
        {8, 2, 0, 3, 9},
        {0, 6, 3, 0, 5},
        {0, 0, 9, 5, 0}
    };
    int ans = get_minimum_spanning_tree_cost_prims_algo(graph1);
    cout << ans << endl;

    return 0;
}
