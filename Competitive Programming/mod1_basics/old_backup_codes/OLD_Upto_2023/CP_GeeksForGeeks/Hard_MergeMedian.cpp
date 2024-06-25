//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);
// #include "../Logger.h"
// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        int n = array1.size() + array2.size();
        vector<int> v((n + 1) / 2 + 1, 0);
        int i = 0, j = 0, k = 0;
        while (k <= ((n + 1) / 2) && i < array1.size() && j < array2.size())
        {
            if (array1[i] <= array2[j])
            {
                v[k++] = array1[i++];
            }
            else
            {
                v[k++] = array2[j++];
            }
        }
        while (k <= ((n + 1) / 2) && i < array1.size())
        {
            v[k++] = array1[i++];
        }
        while (k <= ((n + 1) / 2) && j < array2.size())
        {
            v[k++] = array2[j++];
        }
        if (n % 2 != 0)
        {
            return (double)v[n / 2];
        }
        else
        {
            return (double)((v[n / 2] + (double)v[n / 2 - 1]) / 2);
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
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}

// } Driver Code Ends
