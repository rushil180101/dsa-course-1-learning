#include <bits/stdc++.h>
using namespace std;

/*
Given a directed acyclic graph, print the graph nodes
in topologically sorted order
*/
void display_topological_sort(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> in_degree(n, 0);

    // Initialize in-degrees for all vertices
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (graph[i][j]==1)
            {
                in_degree[j]++;
            }
        }
    }

    // Setup queue with independent nodes (0 in-degree)
    queue<int> q;
    for (int i=0; i<n; i++)
    {
        if (in_degree[i]==0)
        {
            q.push(i);
        }
    }

    // Iterate and decrease in-degree of neighboring nodes
    while (!q.empty())
    {
        int independent = q.front();
        cout << independent << "  ";
        q.pop();
        for (int v=0; v<n; v++)
        {
            if (graph[independent][v]==1)
            {
                in_degree[v]--;
                if (in_degree[v]==0)
                {
                    q.push(v);
                }
            }
        }
    }
    cout << endl;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    vector<vector<int>> graph1 = {
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };
    display_topological_sort(graph1);

    return 0;
}