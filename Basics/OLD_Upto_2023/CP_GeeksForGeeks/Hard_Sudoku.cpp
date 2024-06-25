//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{
    Solution()
    {
        vector<vector<set<int>>> dp(N, vector<set<int>>(N, {1, 2, 3, 4, 5, 6, 7, 8, 9}));
        vector<vector<int>> filled(N, vector<int>(N, 0));
        vector<pair<int, int>> unfilled;
    }
    void initDP(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] != 0)
                    filled[i][j] = 1;
                else
                {
                    unfilled.push_back({i, j});
                }
            }
        }
    }
    void CheckingLines(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                grid[i][j]
            }
        }
    }
    void checkGrid(int grid[N][N], int x, int y)
    {
    }
    void CheckingGrids(int grid[N][N])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                checkGrid(i, j);
            }
        }
    }

public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here
        initDP(grid);
        CheckingLines(grid);
        CheckingGrids(grid);
        for (auto &i :)
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
