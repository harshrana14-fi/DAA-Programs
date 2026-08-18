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

int main() {
    int a[] = {38, 12, 45, 7, 23, 89, 4, 56, 31, 18,
               72, 9, 64, 27, 51, 3, 80, 16, 42, 35};

    int n = sizeof(a) / sizeof(a[0]);

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n\n";

    cout << "Original Array: ";
    for (int x : a) cout << x << " ";

    mergeSort(a, 0, n - 1);

    cout << "\nSorted Array using Merge Sort: ";
    for (int x : a) cout << x << " ";

    return 0;
}