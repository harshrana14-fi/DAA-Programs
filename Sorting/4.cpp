#include <iostream>
using namespace std;

void selectionSort(int a[], int n, int &comparisons) {
    comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        swap(a[i], a[min]);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int best[] = {8, 3, 15, 1, 12, 6, 19, 4, 10, 2,
                  17, 5, 14, 9, 20, 7, 11, 18, 13, 16};

    int worst[] = {20, 3, 18, 5, 16, 7, 14, 9, 12, 1,
                   10, 2, 19, 4, 17, 6, 15, 8, 13, 11};

    int n = 20, comparisons;

    cout << "Name: Harsh Jatoliya\n";
    cout << "Enrollment No.: 13114803124\n";

    cout << "\nBEST CASE\n";
    cout << "Original Array: ";
    printArray(best, n);

    selectionSort(best, n, comparisons);

    cout << "Sorted Array:   ";
    printArray(best, n);

    cout << "\nComplexity Proof:\n";
    cout << "Comparisons = " << comparisons << endl;
    cout << "T(n) = (n-1) + (n-2) + ... + 1\n";
    cout << "T(n) = n(n-1)/2\n";
    cout << "Best Case = O(n^2)\n";

    cout << "\nWORST CASE\n";
    cout << "Original Array: ";
    printArray(worst, n);

    selectionSort(worst, n, comparisons);

    cout << "Sorted Array:   ";
    printArray(worst, n);

    cout << "\nComplexity Proof:\n";
    cout << "Comparisons = " << comparisons << endl;
    cout << "T(n) = (n-1) + (n-2) + ... + 1\n";
    cout << "T(n) = n(n-1)/2\n";
    cout << "Worst Case = O(n^2)\n";

    return 0;
}