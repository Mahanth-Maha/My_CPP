#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given an array of intervals, merge all the overlapping intervals and 
return an array of non-overlapping intervals.
*/

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v(n),ans;
    for(int i = 0 ; i < n ; i++) cin >> v[i].first >> v[i].second ;

    // BRUTE BETTER OPTIMAL :   Time = O(n logn)   Space = O(1)
    // /*
    sort(v.begin(),v.end());
    pair<int,int> temp = v[0];
    for(int i = 1 ; i < n ; i++){
        if(temp.second < v[i].first){
            ans.push_back(temp);
            temp = v[i];
        } else {
            temp.second = max(v[i].second , temp.second);
        }
    }
    ans.push_back(temp);
    // */

    for(int i = 0 ; i < ans.size() ; i++) cout << "[" << ans[i].first << "," << ans[i].second << "]" ;
    return 0;
}
/*
Input :
4
1 3
2 6
8 10
15 18
Output :
[1,6][8,10][15,18]
*/