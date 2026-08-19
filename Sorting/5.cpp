#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int best[] = {12, 4, 17, 9, 2, 15, 6, 20, 8, 11,
                  3, 18, 5, 14, 1, 19, 7, 13, 10, 16};

    int worst[] = {19, 2, 14, 6, 11, 20, 3, 17, 8, 1,
                   15, 5, 12, 7, 18, 4, 10, 16, 9, 13};

    int n = 20;

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n";

    cout << "\nBEST CASE\n";
    cout << "Original Array: ";
    printArray(best, n);

    heapSort(best, n);

    cout << "Sorted Array:   ";
    printArray(best, n);

    cout << "\nComplexity Proof:\n";
    cout << "Heap construction = O(n)\n";
    cout << "Heap height = log2(n)\n";
    cout << "Heapify operations = n\n";
    cout << "T(n) = n * log2(n)\n";
    cout << "Best Case = O(n log n)\n";

    cout << "\nWORST CASE\n";
    cout << "Original Array: ";
    printArray(worst, n);

    heapSort(worst, n);

    cout << "Sorted Array:   ";
    printArray(worst, n);

    cout << "\nComplexity Proof:\n";
    cout << "Heap construction = O(n)\n";
    cout << "Heap height = log2(n)\n";
    cout << "Heapify operations = n\n";
    cout << "T(n) = n * log2(n)\n";
    cout << "Worst Case = O(n log n)\n";

    return 0;
}