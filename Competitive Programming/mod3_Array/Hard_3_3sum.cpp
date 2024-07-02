#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

/*
Given an array of N integers, your task is to find unique triplets 
that add up to give a sum of zero. In short, you need to return an array of 
all the unique triplets [arr[a], arr[b], arr[c]] 
such that i!=j, j!=k, k!=i, and their sum is equal to zero.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(n^3)   Space = O([triplets =n^3])
    /*
    vector<vector<int>> ans;
    set<vector<int>> se;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            for(int k = j+1 ; k < n ; k++) {
                if(v[i] + v[j] +v[k] == 0 ){
                    vector<int> t = {v[i],v[j],v[k]};
                    sort(t.begin(),t.end());
                    se.insert(t);
                }
            }
        }
    }
    for(auto &i : se)
        ans.push_back(i);
    */


    // BETTER :   Time = O(n^2 log n)   Space = O(n^3 + n)
    /*
    set<vector<int>> se;
    for(int i = 0 ; i < n; i++){
        set<int> s;
        for(int j = i+1 ; j < n; j++){
            if(s.find(-(v[i]+ v[j])) != s.end()){
                vector<int> t = {v[i],v[j],-(v[i]+v[j])};
                sort(t.begin(),t.end());
                se.insert(t);
            } else {
                s.insert(v[j]);
            }
        }
    }
    vector<vector<int>> ans(se.begin(),se.end());
    */


    // OPTIMAL :   Time = O(nlogn + n^2) = n^2  Space = O(n^3 + 1)
    // /*
    vector<vector<int>> ans;
    sort(v.begin(),v.end());  // nlogn
    int i = 0;
    while(i < n){
        int j = i + 1, k = n-1;
        while(j < k){
            int s = v[i]+v[j]+v[k];
            if( s == 0 ){
                ans.push_back({v[i],v[j],v[k]});
                while(j < k && v[j] == v[j+1]) j++;
                while(j < k && v[k] == v[k-1]) k--;
                j++;
                k--;
            } else if(s < 0){
                j++;
            } else if(s > 0){
                k--;
            }
        }
        while(v[i] == v[i+1]) i++;
        i++;
    }

    // */

    cout << "[";
    for(int i = 0 ; i < ans.size() ; i++) {
        cout << "[";
        for(int j = 0 ; j < 3 ; j++) 
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << "]";
    return 0;
}
/*
Input :
6
-1 0 1 2 -1 -4
Output :
[[-1 -1 2 ][-1 0 1 ]]

Input :
4
-1 0 1 0
Output :
[[-1 0 1 ][-1 1 0 ]]
*/