#include <iostream>
using namespace std;

void binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int comparisons = 0;
    int position = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        comparisons++;

        if (arr[mid] == key)
        {
            position = mid;
            break;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (position != -1)
    {
        cout << "Element Found at Position: "
             << position + 1 << endl;
    }
    else
    {
        cout << "Element Not Found" << endl;
    }

    cout << "Number of Comparisons = " << comparisons << endl;
}

int main()
{
    cout << "Name: Harsh Jatoliya" << endl;
    cout << "Enrollment No.: 13114803124" << endl;

    // ================= BEST CASE =================
    int bestArr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n1 = 9;
    int bestKey = 50;

    cout << "\nBEST CASE" << endl;

    cout << "Original Array: ";
    for (int i = 0; i < n1; i++)
        cout << bestArr[i] << " ";

    cout << endl;
    cout << "Search Element: " << bestKey << endl;

    binarySearch(bestArr, n1, bestKey);

    cout << "\nComplexity Proof:" << endl;
    cout << "Element is found at the middle position." << endl;
    cout << "Number of comparisons = 1" << endl;
    cout << "T(n) = 1" << endl;
    cout << "Best Case = O(1)" << endl;


    // ================= WORST CASE =================
    int worstArr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n2 = 9;
    int worstKey = 90;

    cout << "\nWORST CASE" << endl;

    cout << "Original Array: ";
    for (int i = 0; i < n2; i++)
        cout << worstArr[i] << " ";

    cout << endl;
    cout << "Search Element: " << worstKey << endl;

    binarySearch(worstArr, n2, worstKey);

    cout << "\nComplexity Proof:" << endl;
    cout << "Search space is divided into half at every step." << endl;
    cout << "Division levels = log2(n)" << endl;
    cout << "Work per level = 1" << endl;
    cout << "T(n) = log2(n)" << endl;
    cout << "Worst Case = O(log n)" << endl;

    return 0;
}