//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // left, up , right, down
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};

public:
    void prints(vector<vector<int>> &vis)
    {
        for (int i = 0; i < vis.size(); i++)
        {
            for (int j = 0; j < vis[0].size(); j++)
            {
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool check(vector<vector<int>> &matrix, vector<vector<int>> &vis, int i, int j, int N, int M)
    {
        bool res = true;
        vis[i][j] = 1;
        for (int p = 0; p < 4; p++)
        {
            int px = i + x[p], py = j + y[p];
            if (px >= 0 && px < N && py >= 0 && py < M)
            {
                cout << "P" << px << "," << py << endl;
                if (matrix[px][py] && !vis[px][py])
                {
                    cout << "OK" << px << "," << py << endl;
                    vis[px][py]++;
                    bool temp = check(matrix, vis, px, py, N, M);
                    res = res && temp;
                }
            }
            else
            {
                cout << "F" << px << "," << py << endl;
                res = false;
            }
        }
        return res;
    }

    int closedIslands(vector<vector<int>> &matrix, int N, int M)
    {
        vector<vector<int>> vis(N, vector<int>(M, 0));
        int nothing = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j] && !vis[i][j])
                {
                    cout << "start " << i << "," << j << endl;
                    if (check(matrix, vis, i, j, N, M))
                    {
                        nothing++;
                        cout << "AT" << i << j << endl;
                    }
                    prints(vis);
                    cout << "end " << i << "," << j << endl;
                }
            }
        }
        return nothing;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> matrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> matrix[i][j];

        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends
