//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void burst(vector<int> arr, int i, int j, vector<vector<int>> &dp)
    {
        vector<int> vis(N + 1, 0);

        dp[i][j] = arr[i - 1] * arr[i] * arr[i + 1];
    }
    int maxCoins(int N, vector<int> &a)
    {
        int maxSum = 0;
        vector<int> arr;
        arr.push_back(1);
        for (auto &i : a)
            arr.push_back(i);
        arr.push_back(1);
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        for (int i = 0; i < N; i++)
        {
            burst(arr, i + 1, 1, dp);
        }

        for (auto &i : dp)
        {
            for (auto &j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }

        return maxSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution S;
        cout << S.maxCoins(n, a) << endl;
    }
    return 0;
}
// } Driver Code Ends
