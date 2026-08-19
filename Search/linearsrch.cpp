#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key)
{
    int comparisons = 0;
    int position = -1;

    for (int i = 0; i < n; i++)
    {
        comparisons++;

        if (arr[i] == key)
        {
            position = i;
            break;
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
    int bestArr[] = {50, 10, 25, 30, 45, 65, 70, 85, 90};
    int n1 = 9;
    int bestKey = 50;

    cout << "\nBEST CASE" << endl;

    cout << "Original Array: ";
    for (int i = 0; i < n1; i++)
        cout << bestArr[i] << " ";

    cout << endl;
    cout << "Search Element: " << bestKey << endl;

    linearSearch(bestArr, n1, bestKey);

    cout << "\nComplexity Proof:" << endl;
    cout << "Element is found at the first position." << endl;
    cout << "Number of comparisons = 1" << endl;
    cout << "T(n) = 1" << endl;
    cout << "Best Case = O(1)" << endl;


    // ================= WORST CASE =================
    int worstArr[] = {10, 25, 30, 45, 65, 70, 85, 90, 100};
    int n2 = 9;
    int worstKey = 100;

    cout << "\nWORST CASE" << endl;

    cout << "Original Array: ";
    for (int i = 0; i < n2; i++)
        cout << worstArr[i] << " ";

    cout << endl;
    cout << "Search Element: " << worstKey << endl;

    linearSearch(worstArr, n2, worstKey);

    cout << "\nComplexity Proof:" << endl;
    cout << "Element is found at the last position." << endl;
    cout << "Number of comparisons = n" << endl;
    cout << "T(n) = n" << endl;
    cout << "Worst Case = O(n)" << endl;

    return 0;
}