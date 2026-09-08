#include <iostream>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    cout << "Name           : Harsh Jatoliya\n";
    cout << "Enrollment No. : 13114803124\n";

    int V, E;

    cout << "\nEnter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edge[E];

    cout << "\nEnter edges (source destination weight):\n";

    for (int i = 0; i < E; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

    int source;

    cout << "\nEnter source vertex (1-" << V << "): ";
    cin >> source;

    source--;

    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Bellman-Ford Algorithm
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edge[j].u - 1;
            int v = edge[j].v - 1;
            int w = edge[j].w;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    bool negativeCycle = false;

    for (int j = 0; j < E; j++)
    {
        int u = edge[j].u - 1;
        int v = edge[j].v - 1;
        int w = edge[j].w;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v])
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "\nNegative weight cycle detected.\n";
    }
    else
    {
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
    }

    cout << "\nCOMPLEXITY ANALYSIS:\n";
    cout << "Best Case               : O(VE)\n";
    cout << "Worst Case              : O(VE)\n";
    cout << "Overall Time Complexity : O(VE)\n";
    cout << "Space Complexity        : O(V + E)\n\n";

    return 0;
}