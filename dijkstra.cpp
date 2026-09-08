#include <iostream>
#include <climits>

using namespace std;

int main()
{
    cout << "Name           : Harsh Jatoliya\n";
    cout << "Enrollment No. : 13114803124\n";

    int V;

    cout << "\nEnter number of vertices: ";
    cin >> V;

    int graph[V][V];

    cout << "\nEnter the adjacency matrix:\n";
    cout << "(Enter 0 if there is no edge)\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    }

    int source;

    cout << "\nEnter source vertex (1-" << V << "): ";
    cin >> source;

    source--;

    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest Distances from Vertex "
         << source + 1 << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << source + 1 << " -> " << i + 1 << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    // Complexity Analysis
    cout << "\nCOMPLEXITY ANALYSIS:\n";

    cout << "Best Case               : O(V^2)\n";
    cout << "Worst Case              : O(V^2)\n";
    cout << "Overall Time Complexity : O(V^2)\n";
    cout << "Space Complexity        : O(V^2)\n\n";

    return 0;
}