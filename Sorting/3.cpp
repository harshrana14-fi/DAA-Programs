#include <iostream>
using namespace std;

void bubbleSort(int a[], int n, int &passes, int &comparisons) {
    passes = comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        passes++;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int best[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int worst[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
                   10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int n = 20, passes, comparisons;

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n";

    cout << "\nBEST CASE\n";
    cout << "Original Array: ";
    printArray(best, n);

    bubbleSort(best, n, passes, comparisons);

    cout << "Sorted Array:   ";
    printArray(best, n);

    cout << "\nComplexity Proof:\n";
    cout << "Passes = " << passes << endl;
    cout << "Comparisons = " << comparisons << endl;
    cout << "T(n) = n - 1\n";
    cout << "Best Case = O(n)\n";

    cout << "\nWORST CASE\n";
    cout << "Original Array: ";
    printArray(worst, n);

    bubbleSort(worst, n, passes, comparisons);

    cout << "Sorted Array:   ";
    printArray(worst, n);

    cout << "\nComplexity Proof:\n";
    cout << "Passes = " << passes << endl;
    cout << "Comparisons = " << comparisons << endl;
    cout << "T(n) = (n-1) + (n-2) + ... + 1\n";
    cout << "T(n) = n(n-1)/2\n";
    cout << "Worst Case = O(n^2)\n";

    return 0;
}