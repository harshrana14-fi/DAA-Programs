
#include <iostream>
#include <vector>
using namespace std;

long long attempts = 0;

bool isSafe(int v, int c, vector<vector<int>>& graph,
            vector<int>& color, int n) {

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }

    return true;
}

bool graphColoring(int v, int m,
                   vector<vector<int>>& graph,
                   vector<int>& color, int n) {

    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        attempts++;

        if (isSafe(v, c, graph, color, n)) {
            color[v] = c;

            if (graphColoring(v + 1, m, graph, color, n))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

void solve(string type) {
    int n, m;

    cout << "\n" << type << " CASE\n";

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of colors: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vector<int> color(n, 0);
    attempts = 0;

    if (graphColoring(0, m, graph, color, n)) {
        cout << "Solution Exists\n";
        cout << "Vertex Coloring:\n";

        for (int i = 0; i < n; i++)
            cout << "Vertex " << i + 1
                 << " -> Color " << color[i] << endl;
    }
    else {
        cout << "No Solution Exists\n";
    }

    cout << "Color Assignment Attempts: "
         << attempts << endl;
}

int main() {
    cout << "GRAPH COLORING USING BACKTRACKING\n";

    solve("BEST");
    solve("WORST");

    cout << "\nBest Case: O(V) for a graph where "
         << "the first color works for every vertex.";
    cout << "\nWorst Case: O(V * m^V)";
    cout << "\nSpace Complexity: O(V^2 + V)\n";

    return 0;
}
