#include <bits/stdc++.h>
using namespace std;

/*
Print graph - Breadth first search traversal (BFS)
- Same as level order traversal in tree using queue
*/
void print_graph_bfs(
    int n,
    vector<vector<int>> graph_adj_matrix,
    int sv,
    vector<bool> &visited
)
{
    queue<int> bfs_traversal_queue;

    // Push start vertex in queue
    bfs_traversal_queue.push(sv);
    // Mark start vertex as visited
    visited[sv] = true;

    while (!bfs_traversal_queue.empty())
    {
        int vertex = bfs_traversal_queue.front();
        bfs_traversal_queue.pop();

        cout << setw(3) << vertex << " ";

        // Push adjacent and non-visited vertices in queue
        for (int i=0; i<n; i++)
        {
            if (graph_adj_matrix[vertex][i]==1 && visited[i]==false)
            {
                bfs_traversal_queue.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

/*
For disconnected graphs, above approach will not work because some vertices
will not have any adjacent vertex, hence, we make use of visited array to
traverse entire disconnected graph
*/
void print_entire_graph_bfs(
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
            print_graph_bfs(n, graph, i, visited);
            connected_components++;
        }
    }
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
        print_graph_bfs(n, graph, start_vertex, visited);
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
        print_graph_bfs(n, graph, start_vertex, visited);
        cout << endl;
    }

    {
        int n = 7, e = 8;
        vector<pair<int, int>> edges = {
            make_pair(0, 1),
            make_pair(0, 2),
            make_pair(1, 3),
            make_pair(1, 4),
            make_pair(2, 6),
            make_pair(3, 5),
            make_pair(4, 5),
            make_pair(6, 5),
        };
        vector<vector<int>> graph = make_graph_from_edge_list(n, edges);

        int start_vertex = 0;
        vector<bool> visited(n, false);
        print_graph_bfs(n, graph, start_vertex, visited);
        cout << endl;
    }

    {
        int n = 8, e = 9;
        vector<pair<int, int>> edges = {
            make_pair(0, 4),
            make_pair(0, 5),
            make_pair(4, 3),
            make_pair(5, 6),
            make_pair(3, 6),
            make_pair(3, 2),
            make_pair(3, 1),
            make_pair(6, 7),
            make_pair(2, 1),
        };
        vector<vector<int>> graph = make_graph_from_edge_list(n, edges);

        int start_vertex = 0;
        vector<bool> visited(n, false);
        print_graph_bfs(n, graph, start_vertex, visited);
        cout << endl;
    }

    cout << "\n\nDisconnected graphs - BFS\n\n";

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
        vector<bool> visited(n, false);
        print_graph_bfs(n, disconnected_graph, start_vertex, visited);

        cout << "\nTraversal using visited array\n";
        print_entire_graph_bfs(n, disconnected_graph);
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
        vector<bool> visited(n, false);
        print_graph_bfs(n, disconnected_graph, start_vertex, visited);

        cout << "\nTraversal using visited array\n";
        print_entire_graph_bfs(n, disconnected_graph);
        cout << endl;
    }

    return 0;
}