#include <iostream>
using namespace std;

int main() {
    int a[] = {38, 12, 45, 7, 23, 89, 4, 56, 31, 18,
               72, 9, 64, 27, 51, 3, 80, 16, 42, 35};

    int n = sizeof(a) / sizeof(a[0]);

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n\n";

    cout << "Original Array: ";
    for (int x : a) cout << x << " ";

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    cout << "\nSorted Array using Bubble Sort: ";
    for (int x : a) cout << x << " ";

    return 0;
}