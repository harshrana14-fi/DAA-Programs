#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    int start;
    int finish;
};

// Sort activities according to finish time
bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

// Activity Selection Function
void activitySelection(Activity activities[], int n)
{
    // Sort according to finish time
    sort(activities, activities + n, compare);

    cout << "Activities after sorting by finish time:" << endl;

    cout << "Activity\tStart\tFinish" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "A" << i + 1 << "\t\t"
             << activities[i].start << "\t"
             << activities[i].finish << endl;
    }

    cout << "\nSelected Activities: ";

    // Select first activity
    int lastFinish = activities[0].finish;

    cout << "A1 ";

    // Select remaining activities
    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= lastFinish)
        {
            cout << "A" << i + 1 << " ";
            lastFinish = activities[i].finish;
        }
    }

    cout << endl;
}

int main()
{
    cout << "Name: Harsh Jatoliya" << endl;
    cout << "Enrollment No.: 13114803124" << endl;

    // =====================================================
    // BEST CASE
    // =====================================================

    Activity bestCase[] =
    {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    int n1 = 5;

    cout << "\nBEST CASE" << endl;

    cout << "Original Activities:" << endl;
    cout << "Activity\tStart\tFinish" << endl;

    for (int i = 0; i < n1; i++)
    {
        cout << "A" << i + 1 << "\t\t"
             << bestCase[i].start << "\t"
             << bestCase[i].finish << endl;
    }

    cout << endl;

    activitySelection(bestCase, n1);

    cout << "\nComplexity Proof:" << endl;
    cout << "Step 1: Sort activities according to finish time." << endl;
    cout << "Sorting Time = O(n log n)" << endl;
    cout << "Step 2: Traverse all activities once." << endl;
    cout << "Selection Time = O(n)" << endl;
    cout << "T(n) = O(n log n) + O(n)" << endl;
    cout << "T(n) = O(n log n)" << endl;
    cout << "Best Case = O(n log n)" << endl;


    // =====================================================
    // WORST CASE
    // =====================================================

    Activity worstCase[] =
    {
        {0, 10},
        {1, 9},
        {2, 8},
        {3, 7},
        {4, 6}
    };

    int n2 = 5;

    cout << "\n\nWORST CASE" << endl;

    cout << "Original Activities:" << endl;
    cout << "Activity\tStart\tFinish" << endl;

    for (int i = 0; i < n2; i++)
    {
        cout << "A" << i + 1 << "\t\t"
             << worstCase[i].start << "\t"
             << worstCase[i].finish << endl;
    }

    cout << endl;

    activitySelection(worstCase, n2);

    cout << "\nComplexity Proof:" << endl;
    cout << "Step 1: Sort activities according to finish time." << endl;
    cout << "Sorting Time = O(n log n)" << endl;
    cout << "Step 2: Traverse all activities once." << endl;
    cout << "Selection Time = O(n)" << endl;
    cout << "T(n) = O(n log n) + O(n)" << endl;
    cout << "T(n) = O(n log n)" << endl;
    cout << "Worst Case = O(n log n)" << endl;

    return 0;
}