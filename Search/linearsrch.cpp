#include <iostream>
using namespace std;

int main() {
    int a[] = {13, 14, 95, 47, 23, 89, 4, 56, 31, 118,
               72, 9, 54, 27, 51, 63, 80, 16, 42, 35};

    int n = sizeof(a) / sizeof(a[0]);
    int key = 64, pos = -1;

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n\n";

    cout << "Array: ";
    for (int x : a) cout << x << " ";

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            pos = i;
            break;
        }
    }

    cout << "\nKey: " << key;

    if (pos != -1)
        cout << "\nElement found at position: " << pos + 1;
    else
        cout << "\nElement not found";

    return 0;
}