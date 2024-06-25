#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareTuples(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int minTuplesToCover(int N, vector<pair<int, int>>& ranges) {
    // Sort the list of tuples based on the ending point (y)
    sort(ranges.begin(), ranges.end(), compareTuples);
    
    int count = 0;
    int current_max = 0;
    
    for (int i = 0; i < ranges.size(); ++i) {
        int x = ranges[i].first;
        int y = ranges[i].second;
        
        if (x > current_max) {
            // Select the current tuple and update current_max
            count++;
            current_max = y;
        } else {
            // Update current_max if there is an overlap
            current_max = max(current_max, y);
        }
    }
    
    return count;
}

int main() {
    int N = 10;
    vector<pair<int, int>> ranges = {{1, 2}, {1, 3}, {2, 4}, {2, 5},{4,5}};
    int result = minTuplesToCover(N, ranges);
    // cout << "Minimum number of tuples to cover: " << result << endl;
    cout << result << endl;
    return 0;
}
