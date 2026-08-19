#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int t[20], i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
        t[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = t[k++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int best[] = {12, 5, 19, 3, 15, 8, 1, 17, 10, 6,
                  14, 2, 20, 7, 11, 4, 18, 9, 13, 16};

    int worst[] = {20, 18, 15, 13, 11, 9, 7, 5, 3, 1,
                   19, 17, 14, 12, 10, 8, 6, 4, 2, 16};

    int n = 20;

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n";

    cout << "\nBEST CASE\n";
    cout << "Original Array: ";
    printArray(best, n);

    mergeSort(best, 0, n - 1);

    cout << "Sorted Array:   ";
    printArray(best, n);

    cout << "\nComplexity Proof:\n";
    cout << "Division levels = log2(n)\n";
    cout << "Work per level = n\n";
    cout << "T(n) = n * log2(n)\n";
    cout << "Best Case = O(n log n)\n";

    cout << "\nWORST CASE\n";
    cout << "Original Array: ";
    printArray(worst, n);

    mergeSort(worst, 0, n - 1);

    cout << "Sorted Array:   ";
    printArray(worst, n);

    cout << "\nComplexity Proof:\n";
    cout << "Division levels = log2(n)\n";
    cout << "Work per level = n\n";
    cout << "T(n) = n * log2(n)\n";
    cout << "Worst Case = O(n log n)\n";

    return 0;
}