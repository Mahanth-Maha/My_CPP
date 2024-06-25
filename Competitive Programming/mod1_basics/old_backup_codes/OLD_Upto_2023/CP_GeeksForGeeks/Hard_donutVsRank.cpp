#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinTime(int N, vector<int> &A, int L)
    {
        int time = 0;

        return time;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l;
        cin >> l;
        vector<int> arr(l);
        for (int i = 0; i < l; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        int ans = ob.findMinTime(n, arr, l);
        cout << ans << endl;
    }
    return 0;
}
