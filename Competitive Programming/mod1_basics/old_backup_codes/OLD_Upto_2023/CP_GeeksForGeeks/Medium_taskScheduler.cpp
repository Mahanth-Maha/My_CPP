//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// #include "../Logger.h"
// } Driver Code Ends
class Solution
{
public:
    int leastInterval(int N, int K, vector<char> &tasks)
    {
        vector<int> noOfTasks(26, 0);
        for (int i = 0; i < tasks.size(); i++)
        {
            noOfTasks[tasks[i] - 'A']++;
        }
        sort(noOfTasks.begin(), noOfTasks.end(), greater<>());
        map<int, char> timeline;
        for (int i = 0; i < 26; i++)
        {
            int k = 0;
            for (int j = 0; j < noOfTasks[i]; j++)
            {
                while (timeline[k] != 0)
                {
                    k++;
                }
                timeline[k++] = 'A' + i;
                k += K;
            }
        }
        // log_map(timeline);
        auto it = timeline.end();
        it--;
        return (*it).first + 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++)
            cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
