
#include <iostream>
#include "../Logger.h"

using namespace std;

string solve(string dict[], int N, int K)
{
    // TODO: Topological Sort

    // Step 1 : Build the graph
    unordered_map<char, vector<char>> graph;
    graph[dict[0][0]] = vector<char>();

    for (int i = 1; i < N; i++)
    {
        int j = 0;
        while (dict[i - 1].size() > j && dict[i].size() > j && dict[i - 1][j] == dict[i][j])
        {
            j++;
        }
        if (dict[i - 1].size() > j && dict[i].size() > j && dict[i - 1][j] != dict[i][j])
        {
            graph[dict[i - 1][j]].push_back(dict[i][j]);
        }
    }
    // for (auto &it : graph)
    // {
    //     cout << it.first << ":";
    //     for (auto &itv : it.second)
    //         cout << itv << " ";
    //     cout << "\n";
    // }

    // Step 2 : find edges with no incoming edges
    unordered_map<char, int> incoming_edges;
    for (auto &it : graph)
    {
        incoming_edges[it.first] = 0;
    }
    for (auto &it : graph)
    {
        for (auto &itv : it.second)
        {
            incoming_edges[itv]++;
        }
    }
    priority_queue<pair<int, char>> pqic;
    for (auto &it : incoming_edges)
    {
        if (it.second == 0)
        {
            pqic.push({it.second, it.first});
        }
    }

    // Step 3 : TopoSort
    string result = "";
    unordered_set<char> visited;

    while (!pqic.empty())
    {
        pair<int, char> p = pqic.top();
        pqic.pop();
        if (visited.find(p.second) == visited.end())
        {
            visited.insert(p.second);
            result += p.second;
            for (auto &itv : graph[p.second])
            {
                incoming_edges[itv]--;
                if (incoming_edges[itv] == 0)
                {
                    pqic.push({incoming_edges[itv], itv});
                }
            }
        }
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string dict[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    cout << solve(dict, n, k) << endl;
    return 0;
}
