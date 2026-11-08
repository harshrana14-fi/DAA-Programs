
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long operations;

void LCS(string a, string b) {
    int m = a.length();
    int n = b.length();

    vector<vector<int>> dp(
        m + 1, vector<int>(n + 1, 0));

    operations = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            operations++;

            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(
                    dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans;
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());

    cout << "String 1: " << a << endl;
    cout << "String 2: " << b << endl;
    cout << "Longest Common Subsequence: " << ans << endl;
    cout << "LCS Length: " << dp[m][n] << endl;
    cout << "DP Operations: " << operations << endl;
}

int main() {
    string a, b;

    cout << "LONGEST COMMON SUBSEQUENCE\n";

    cout << "\nBEST CASE INPUT\n";
    cout << "Enter first string: ";
    cin >> a;
    cout << "Enter second string: ";
    cin >> b;

    LCS(a, b);

    cout << "\nWORST CASE INPUT\n";
    cout << "Enter first string: ";
    cin >> a;
    cout << "Enter second string: ";
    cin >> b;

    LCS(a, b);

    cout << "\nTime Complexity: O(m*n)";
    cout << "\nSpace Complexity: O(m*n)\n";

    return 0;
}
