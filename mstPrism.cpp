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
        {
            cin >> graph[i][j];
        }
    }

    int key[V];
    int parent[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    // Prim's Algorithm
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        // Find minimum key vertex
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] + 1 << " - "
             << i + 1 << " : "
             << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    // Complexity Analysis
    cout << "\nCOMPLEXITY ANALYSIS:\n";
    cout << "Vertices (V)            : " << V << endl;

    cout << "\nBest Case               : O(V^2)\n";
    cout << "Worst Case              : O(V^2)\n";
    cout << "Overall Time Complexity : O(V^2)\n";
    cout << "Space Complexity        : O(V^2)\n";

    return 0;
}