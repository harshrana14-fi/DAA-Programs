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

int main() {
    int a[] = {38, 12, 45, 7, 23, 89, 4, 56, 31, 18,
               72, 9, 64, 27, 51, 3, 80, 16, 42, 35};

    int n = sizeof(a) / sizeof(a[0]);

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n\n";

    cout << "Original Array: ";
    for (int x : a) cout << x << " ";

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }

    cout << "\nSorted Array using Heap Sort: ";
    for (int x : a) cout << x << " ";

    return 0;
}