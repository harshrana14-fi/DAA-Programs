#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, w;
};

bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

int findParent(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;

    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent)
{
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (a != b)
        parent[b] = a;
}

int main()
{
    cout << "Name           : Harsh Jatoliya\n";
    cout << "Enrollment No. : 13114803124\n";

    int V, E;

    cout << "\nEnter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "\nEnter edges (source destination weight):\n";

    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V + 1);

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    // Kruskal's Algorithm
    for (Edge e : edges)
    {
        if (findParent(e.u, parent) != findParent(e.v, parent))
        {
            mst.push_back(e);
            totalWeight += e.w;

            unionSet(e.u, e.v, parent);
        }

        if (mst.size() == V - 1)
            break;
    }

    cout << "\nMinimum Spanning Tree:\n";

    for (Edge e : mst)
        cout << e.u << " - " << e.v
             << " : " << e.w << endl;

    cout << "\nMinimum Cost = " << totalWeight << endl;

    // Complexity Analysis
    cout << "\nCOMPLEXITY ANALYSIS:\n";

    cout << "Vertices (V)            : " << V << endl;
    cout << "Edges (E)               : " << E << endl;

    cout << "\nTime Complexity:\n";
    cout << "Sorting Edges           : O(E log E)\n";
    cout << "Cycle Detection         : O(E log V)\n";

    cout << "\nBest Case               : O(E log E)\n";
    cout << "Worst Case              : O(E log E)\n";
    cout << "Overall Time Complexity : O(E log E)\n";

    cout << "\nSpace Complexity        : O(V + E)\n";

    return 0;
}