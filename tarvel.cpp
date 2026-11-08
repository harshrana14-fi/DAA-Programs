
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

int bestCost;
int nodesVisited;
int pruned;
vector<int> bestPath;
vector<int> minOut;

int lowerBound(vector<bool>& visited, int current, int n) {
    int bound = minOut[current];

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            bound += minOut[i];
    }

    return bound;
}

void TSP(vector<vector<int>>& cost,
         vector<bool>& visited,
         vector<int>& path,
         int current, int currentCost, int n) {

    nodesVisited++;

    if (path.size() == n) {
        int total = currentCost + cost[current][0];

        if (total < bestCost) {
            bestCost = total;
            bestPath = path;
            bestPath.push_back(0);
        }
        return;
    }

    int bound = lowerBound(visited, current, n);

    if (currentCost + bound >= bestCost) {
        pruned++;
        return;
    }

    for (int next = 1; next < n; next++) {
        if (!visited[next]) {

            visited[next] = true;
            path.push_back(next);

            TSP(cost, visited, path, next,
                currentCost + cost[current][next], n);

            path.pop_back();
            visited[next] = false;
        }
    }
}

void solve(string type) {
    int n;

    cout << "\n" << type << " CASE\n";

    cout << "Enter number of cities: ";
    cin >> n;

    if (n < 2) {
        cout << "At least 2 cities are required.\n";
        return;
    }

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost adjacency matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Precompute minimum outgoing edge of each city
    minOut.assign(n, INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j)
                minOut[i] = min(minOut[i], cost[i][j]);
        }
    }

    bestCost = INF;
    nodesVisited = 0;
    pruned = 0;
    bestPath.clear();

    vector<bool> visited(n, false);
    vector<int> path;

    visited[0] = true;
    path.push_back(0);

    TSP(cost, visited, path, 0, 0, n);

    if (bestCost == INF) {
        cout << "No valid tour found.\n";
        return;
    }

    cout << "\nMinimum Tour Cost: " << bestCost;

    cout << "\nOptimal Path: ";
    for (int city : bestPath)
        cout << city + 1 << " ";

    cout << "\nNodes Visited: " << nodesVisited;
    cout << "\nBranches Pruned: " << pruned << endl;
}

int main() {
    cout << "TRAVELLING SALESMAN PROBLEM\n";
    cout << "Using Branch and Bound\n";

    solve("BEST");
    solve("WORST");

    cout << "\nWorst Case Time Complexity: O(n * n!)";
    cout << "\nSpace Complexity: O(n)\n";

    return 0;
}
