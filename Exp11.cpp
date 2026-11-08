
#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;

void compareSwap(vector<int>& a, int i, int j,
                 bool ascending) {
    comparisons++;

    if ((ascending && a[i] > a[j]) ||
        (!ascending && a[i] < a[j]))
        swap(a[i], a[j]);
}

void bitonicMerge(vector<int>& a, int low,
                  int cnt, bool ascending) {
    if (cnt > 1) {
        int k = cnt / 2;

        for (int i = low; i < low + k; i++)
            compareSwap(a, i, i + k, ascending);

        bitonicMerge(a, low, k, ascending);
        bitonicMerge(a, low + k, k, ascending);
    }
}

void bitonicSort(vector<int>& a, int low,
                 int cnt, bool ascending) {
    if (cnt > 1) {
        int k = cnt / 2;

        bitonicSort(a, low, k, true);
        bitonicSort(a, low + k, k, false);

        bitonicMerge(a, low, cnt, ascending);
    }
}

void solve(string type) {
    int n;

    cout << "\n" << type << " CASE\n";
    cout << "Enter array size (power of 2): ";
    cin >> n;

    if (n <= 0 || (n & (n - 1)) != 0) {
        cout << "Invalid size! Enter a power of 2.\n";
        return;
    }

    vector<int> a(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    comparisons = 0;

    cout << "Original Array: ";
    for (int x : a)
        cout << x << " ";

    bitonicSort(a, 0, n, true);

    cout << "\nSorted Array: ";
    for (int x : a)
        cout << x << " ";

    cout << "\nNumber of Comparisons: "
         << comparisons << endl;
}

int main() {
    cout << "BITONIC SORTING NETWORK\n";

    solve("BEST");
    solve("WORST");

    cout << "\nTime Complexity: O(n log^2 n)";
    cout << "\nSpace Complexity: O(log n)\n";

    return 0;
}
