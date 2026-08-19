#include <iostream>
using namespace std;

int partition(int a[], int l, int r) {
    int mid = (l + r) / 2;
    swap(a[mid], a[l]);

    int pivot = a[l];
    int i = l + 1;

    for (int j = l + 1; j <= r; j++) {
        if (a[j] < pivot)
            swap(a[i++], a[j]);
    }

    swap(a[l], a[i - 1]);
    return i - 1;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int best[] = {1, 3, 2, 5, 4, 7, 6, 9, 8, 11,
                  10, 13, 12, 15, 14, 17, 16, 19, 18, 20};

    int worst[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int n = 20;

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n";

    cout << "\nBEST CASE\n";
    cout << "Original Array: ";
    printArray(best, n);

    quickSort(best, 0, n - 1);

    cout << "Sorted Array:   ";
    printArray(best, n);

    cout << "\nComplexity Proof:\n";
    cout << "Partitions are approximately balanced.\n";
    cout << "Levels = log2(n)\n";
    cout << "Work per level = n\n";
    cout << "T(n) = n * log2(n)\n";
    cout << "Best Case = O(n log n)\n";

    cout << "\nWORST CASE\n";
    cout << "Original Array: ";
    printArray(worst, n);

    quickSort(worst, 0, n - 1);

    cout << "Sorted Array:   ";
    printArray(worst, n);

    cout << "\nComplexity Proof:\n";
    cout << "Partitions become highly unbalanced.\n";
    cout << "Partition = (n-1) + 0\n";
    cout << "T(n) = n + (n-1) + ... + 1\n";
    cout << "T(n) = n(n-1)/2\n";
    cout << "Worst Case = O(n^2)\n";

    return 0;
}