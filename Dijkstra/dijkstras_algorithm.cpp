#include <bits/stdc++.h>
using namespace std;

int get_min_dist_idx(
    vector<int> &distance,
    vector<bool> &visited
)
{
    int min_idx = 0;
    int min_dist = 1000;
    for (int i=0; i<distance.size(); i++)
    {
        if (distance[i]<min_dist && visited[i]==false)
        {
            min_dist = distance[i];
            min_idx = i;
        }
    }
    return min_idx;
}

/*
Dijkstras algorithm - Find the shortest path between given source
node and every other node
*/
vector<int> get_shortest_paths_dijkstras(
    int source_node,
    vector<vector<int>> graph
)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);
    distance[source_node] = 0;

    for (int count=0; count<n; count++)
    {
        int u = get_min_dist_idx(distance, visited);
        // go through all non-visited neighbours
        for (int v=0; v<n; v++)
        {
            if (u!=v && visited[v]==false)
            {
                if (distance[u]+graph[u][v]<distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
        // mark current node as visited
        visited[u] = true;
    }
    return distance;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int inf = 1000;
    vector<vector<int>> graph1 = {
        {0, 4, inf, inf, inf, 1},
        {4, 0, 8, inf, inf, 2},
        {inf, 8, 0, 3, inf, inf},
        {inf, inf, 3, 0, 2, inf},
        {inf, inf, inf, 2, 0, 1},
        {1, 2, inf, inf, 1, 0}
    };
    vector<int> shortest_paths = get_shortest_paths_dijkstras(
        0, graph1
    );
    for (int i=0; i<shortest_paths.size(); i++)
    {
        cout << shortest_paths[i] << "  ";
    }
    cout << endl;

    return 0;
}