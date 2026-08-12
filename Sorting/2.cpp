#include <iostream>
using namespace std;

// Insertion Sort
// Best Case    : O(n)     -> array is already sorted
// Average Case : O(n^2)
// Worst Case   : O(n^2)   -> elements are in reverse order
// Space        : O(1)

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    cout << "Name : Harsh Jatoliya" << endl;
    cout << "Enrollment No. : 13114803124" << endl << endl;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    cout << "Sorted Array using Insertion Sort: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}