
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 99999;

long long operations = 0;

void floydWarshall(vector<vector<int>> dist,
                   string type) {

    int V = dist.size();
    operations = 0;

    cout << "\n" << type << " CASE\n";

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                operations++;

                if (dist[i][k] != INF &&
                    dist[k][j] != INF) {

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Total Operations: "
         << operations << endl;
}

vector<vector<int>> getInput() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter weighted adjacency matrix ";
    cout << "(-1 for no edge):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            if (x == -1)
                graph[i][j] = INF;
            else
                graph[i][j] = x;
        }
    }

    return graph;
}

int main() {
    cout << "FLOYD WARSHALL ALGORITHM\n";

    cout << "\nBEST CASE INPUT\n";
    vector<vector<int>> best = getInput();
    floydWarshall(best, "BEST");

    cout << "\nWORST CASE INPUT\n";
    vector<vector<int>> worst = getInput();
    floydWarshall(worst, "WORST");

    cout << "\nTime Complexity: O(V^3)";
    cout << "\nSpace Complexity: O(V^2)\n";

    return 0;
}
