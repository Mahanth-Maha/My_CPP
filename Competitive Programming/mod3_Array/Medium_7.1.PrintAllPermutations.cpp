#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Print all permutations

void all_permute(vector<int> &v, vector<int>& vis, vector<vector<int>> &permutes,vector<int> temp){
    if(temp.size() == v.size()) {
        permutes.push_back(temp); 
        return ;
    }
    for(int i = 0 ; i < vis.size();i++){
        if(vis[i] == 0) {
            temp.push_back(v[i]);
            vis[i] = 1;
            all_permute(v,vis,permutes,temp);
            vis[i] = 0;
            temp.pop_back();
        } 
    }
}

void all_permute_2(vector<int>& v,vector<vector<int>> &permute,int i){
    int tempi = v[i];
    if(i == v.size())
        permute.push_back(v);
    for(int k = i ; k < v.size(); k++){
        int tempk = v[k];
        v[i] = tempk;
        v[k] = tempi;
        all_permute_2(v,permute,i+1);
        v[i] = tempi;
        v[k] = tempk;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    vector<vector<int>>permutes;

    // BRUTE :   Time = O(n* n!)   Space = O(n + n!)
    /*
    vector<int> vis(n,0),temp;
    sort(v.begin(), v.end());
    all_permute(v,vis,permutes,temp);
    */


    // BETTER :   Time = O()   Space = O()
    // /*
    vector<int> vis(n,0),temp;
    sort(v.begin(), v.end());
    all_permute_2(v,permutes,0);
    sort(permutes.begin(),permutes.end());
    // */


    // OPTIMAL :   Time = O()   Space = O()
    // /*
    
    // */
    cout << "[";
    for(auto &i:permutes){
        cout << "[";
        for(auto &j:i)
            cout << j << " " ;
        cout << "] ";
    }
    cout << "]";
    return 0;
}
/*
Input :
3
1 2 3
Output :
[[1 2 3 ] [1 3 2 ] [2 1 3 ] [2 3 1 ] [3 1 2 ] [3 2 1 ] ]

Input :
1
1
Output :
[[1 ] ]


Input :
4
1 2 3 4
Output :
[[1 2 3 4 ] [1 2 4 3 ] [1 3 2 4 ] [1 3 4 2 ] [1 4 2 3 ] [1 4 3 2 ] [2 1 3 4 ] [2 1 4 3 ] [2 3 1 4 ] [2 3 4 1 ] [2 4 1 3 ] [2 4 3 1 ] [3 1 2 4 ] [3 1 4 2 ] [3 2 1 4 ] [3 2 4 1 ] [3 4 1 2 ] [3 4 2 1 ] [4 1 2 3 ] [4 1 3 2 ] [4 2 1 3 ] [4 2 3 1 ] [4 3 1 2 ] [4 3 2 1 ] ]

*/