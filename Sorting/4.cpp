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
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        swap(a[i], a[min]);
    }

    cout << "\nSorted Array using Selection Sort: ";
    for (int x : a) cout << x << " ";

    return 0;
}