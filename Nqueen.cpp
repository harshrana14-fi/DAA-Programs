#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;

bool isSafe(int row, int col)
{
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(int row)
{
    if (row == N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main()
{
    cout << "Name           : Harsh Jatoliya\n";
    cout << "Enrollment No. : 13114803124\n";

    cout << "\nEnter number of queens: ";
    cin >> N;

    board.assign(N, vector<int>(N, 0));

    if (solveNQueens(0))
    {
        cout << "\nSolution:\n";

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\nNo solution exists for " << N << " queens.\n";
    }

    cout << "\nCOMPLEXITY ANALYSIS:\n";
    cout << "Best Case               : O(N!)\n";
    cout << "Worst Case              : O(N!)\n";
    cout << "Overall Time Complexity : O(N!)\n";
    cout << "Space Complexity        : O(N^2)\n";

    return 0;
}