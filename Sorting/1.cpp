#include <iostream>
using namespace std;

// Bubble Sort
// Time Complexity:
// Best Case    : O(n)     -> array is already sorted
// Average Case : O(n^2)   -> nested comparisons
// Worst Case   : O(n^2)   -> maximum comparisons and swaps
// Space        : O(1)

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    bubbleSort(arr, n);

    cout << "Sorted Array using Bubble Sort: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}