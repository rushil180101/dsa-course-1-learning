#include <bits/stdc++.h>
using namespace std;

/*
Print the graph - Depth first search (DFS)
1. Select starting vertex
2. Call recursion on all the adjacent vertices of the starting vertex
3. Mark/store visited vertices and do not traverse them again
*/
void print_graph_dfs(
    int n,
    vector<vector<int>> graph,
    int start_vertex,
    vector<bool> &visited
)
{
    // Print start (current) vertex
    cout << setw(3) << start_vertex << " ";
    // Mark start (current) vertex as visited
    visited[start_vertex] = true;

    // Call recursion on all adjacent and non-visited vertices of start (current) vertex
    for (int i=0; i<n; i++)
    {
        if (graph[start_vertex][i]==1 && visited[i]==false)
        {
            print_graph_dfs(
                n,
                graph,
                i,
                visited
            );
        }
    }
}

/*
For disconnected graphs, above dfs approach will not work because
some vertices will not have any adjacent vertex, hence, all vertices will
not be visited. Thus, we can make use of visited vector to print
entire disconnected graph.
*/
void print_entire_graph_dfs(
    int n,
    vector<vector<int>> graph
)
{
    vector<bool> visited(n, false);
    int connected_components = 0;
    for (int i=0; i<visited.size(); i++)
    {
        if (visited[i]==false)
        {
            print_graph_dfs(n, graph, i, visited);
            connected_components++;
        }
    }
    cout << endl;
    cout << "Connected components = " << connected_components;
    cout << endl;
}

vector<vector<int>> make_graph_from_edge_list(int n, vector<pair<int, int>> edges)
{
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i=0; i<edges.size(); i++)
    {
        int m = edges[i].first;
        int n = edges[i].second;
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
    return graph;
}

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    {
        int n = 7, e = 7;
        vector<pair<int, int>> edges = {
            make_pair(0, 1),
            make_pair(0, 2),
            make_pair(1, 5),
            make_pair(2, 3),
            make_pair(5, 4),
            make_pair(3, 4),
            make_pair(2, 6),
        };
        vector<vector<int>> graph = make_graph_from_edge_list(n, edges);

        int start_vertex = 0;
        vector<bool> visited(n, false);
        print_graph_dfs(n, graph, start_vertex, visited);
        cout << endl;
    }

    {
        int n = 9, e = 11;
        vector<pair<int, int>> edges = {
            make_pair(0, 1),
            make_pair(0, 4),
            make_pair(0, 3),
            make_pair(1, 2),
            make_pair(1, 6),
            make_pair(4, 6),
            make_pair(4, 3),
            make_pair(2, 7),
            make_pair(6, 7),
            make_pair(3, 5),
            make_pair(3, 8),
        };
        vector<vector<int>> graph = make_graph_from_edge_list(n, edges);

        int start_vertex = 0;
        vector<bool> visited(n, false);
        print_graph_dfs(n, graph, start_vertex, visited);
        cout << endl;
    }

    // Disconnected graphs
    cout << "\n\nDisconnected graphs - DFS\n\n";

    {
        int n = 8, e = 6;
        vector<pair<int, int>> edges = {
            make_pair(0, 2),
            make_pair(0, 4),
            make_pair(2, 4),
            make_pair(2, 3),
            make_pair(1, 5),
            make_pair(6, 7),
        };
        vector<vector<int>> disconnected_graph = make_graph_from_edge_list(n, edges);
        int start_vertex = 0;
        cout << "\nNormal traversal without using visited array\n";
        vector<bool> visited1(n, false);
        print_graph_dfs(n, disconnected_graph, start_vertex, visited1);

        cout << "\nTraversal using visited array\n";
        print_entire_graph_dfs(n, disconnected_graph);
        cout << endl;
        cout << endl;
    }

    {
        int n = 7, e = 7;
        vector<pair<int, int>> edges = {
            make_pair(0, 1),
            make_pair(1, 3),
            make_pair(1, 6),
            make_pair(3, 6),
            make_pair(2, 4),
            make_pair(2, 5),
            make_pair(4, 5),
        };
        vector<vector<int>> disconnected_graph = make_graph_from_edge_list(n, edges);
        int start_vertex = 0;
        cout << "\nNormal traversal without using visited array\n";
        vector<bool> visited1(n, false);
        print_graph_dfs(n, disconnected_graph, start_vertex, visited1);

        cout << "\nTraversal using visited array\n";
        print_entire_graph_dfs(n, disconnected_graph);
        cout << endl;
        cout << endl;
    }


    return 0;
}