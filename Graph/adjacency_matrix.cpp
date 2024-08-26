#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // ########################## //
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ########################## //

    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;

    int graph[vertices][vertices] = {0};
    int v1, v2;
    for (int i=0; i<edges; i++)
    {
        cin >> v1;
        cin >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    cout << "\n\nGraph - Adjacency matrix\n\n";
    for (int i=0; i<vertices; i++)
    {
        for (int j=0; j<vertices; j++)
        {
            cout << setw(3) << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}