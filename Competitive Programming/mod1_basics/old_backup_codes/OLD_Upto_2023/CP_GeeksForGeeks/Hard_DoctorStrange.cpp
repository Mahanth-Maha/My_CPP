//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isConnected(vector<vector<int>> &graph)
    {
        vector<int> visited;
        queue<int> que;
    }
    int doctorStrange(int N, int M, vector<vector<int>> &graph)
    {
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        vector<vector<int>> g(n + 1);
        for (i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
