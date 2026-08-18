#include <iostream>
using namespace std;

void quickSort(int a[], int l, int r) {
    if (l >= r) return;

    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quickSort(a, l, j);
    quickSort(a, i, r);
}

int main() {
    int a[] = {38, 12, 45, 7, 23, 89, 4, 56, 31, 18,
               72, 9, 64, 27, 51, 3, 80, 16, 42, 35};

    int n = sizeof(a) / sizeof(a[0]);

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n\n";

    cout << "Original Array: ";
    for (int x : a) cout << x << " ";

    quickSort(a, 0, n - 1);

    cout << "\nSorted Array using Quick Sort: ";
    for (int x : a) cout << x << " ";

    return 0;
}