
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long operations;

long long matrixChain(vector<int> p) {
    int n = p.size() - 1;

    vector<vector<long long>> dp(
        n + 1, vector<long long>(n + 1, 0));

    operations = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                operations++;

                long long cost = dp[i][k] +
                    dp[k + 1][j] +
                    1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

void inputCase(string name) {
    int n;
    cout << "\n" << name << " CASE\n";

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    cout << "Minimum Multiplication Cost: "
         << matrixChain(p) << endl;

    cout << "Number of Operations: "
         << operations << endl;
}

int main() {
    cout << "MATRIX CHAIN MULTIPLICATION\n";

    cout << "\nEnter BEST CASE input:";
    inputCase("BEST");

    cout << "\nEnter WORST CASE input:";
    inputCase("WORST");

    cout << "\nTime Complexity: O(n^3)";
    cout << "\nSpace Complexity: O(n^2)\n";

    return 0;
}
