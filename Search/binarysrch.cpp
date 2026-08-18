#include <iostream>
using namespace std;

int main() {
    int a[] = {13, 14, 95, 47, 23, 89, 4, 56, 31, 118,
               72, 9, 54, 27, 51, 63, 80, 16, 42, 35};

    int n = sizeof(a) / sizeof(a[0]);
    int key = 64;
    int l = 0, r = n - 1, pos = -1;

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n\n";

    cout << "Sorted Array: ";
    for (int x : a) cout << x << " ";

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m] == key) {
            pos = m;
            break;
        }
        else if (a[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }

    cout << "\nKey: " << key;

    if (pos != -1)
        cout << "\nElement found at position: " << pos + 1;
    else
        cout << "\nElement not found";

    return 0;
}