#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

/*
Given an array of N integers, your task is to find unique quads 
that add up to give a target value. 
In short, you need to return an array of all the unique quadruplets 
[arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
*/

int main()
{
    int n , target;
    cin >> n >> target;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(n^4)   Space = O(n^4 + 1)        (Quads + Extra Space)
    /*
    set<vector<int>> se;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            for(int k = j+1 ; k < n ; k++) {
                for(int l = k+1 ; l < n ; l++) {
                    if(v[i] + v[j] + v[k] + v[l] == target ){
                        vector<int> t = {v[i],v[j],v[k],v[l]};
                        sort(t.begin(),t.end());
                        se.insert(t);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(se.begin(),se.end());
    */


    // BETTER :   Time = O(n^3 log n)   Space = O(n^4 + n)
    /*
    set<vector<int>> se;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            set<int> s;
            for(int k = j+1 ; k < n ; k++) {
                int sum3 = v[i] + v[j] + v[k];
                if( s.find( target - sum3) != s.end()){
                    vector<int> t = {v[i],v[j],v[k],target - sum3};
                    sort(t.begin(),t.end());
                    se.insert(t);
                } else s.insert(v[k]);
            }
        }
    }
    vector<vector<int>> ans(se.begin(),se.end());
    */


    // OPTIMAL :   Time = O( nlogn + n^3) = n^3   Space = O(n^4 + 1)
    // /*
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            int k = j+1, l = n-1;
            while(k < l){
                int sum = v[i]+v[j]+v[k]+v[l] ;
                if(sum == target){
                    ans.push_back({v[i],v[j],v[k],v[l]});
                    while(k < l && v[k] == v[k+1]) k++;
                    k++;
                    while(k < l && v[l] == v[l-1]) l--;
                    l--;
                } else if(sum < target)
                    k++;
                else 
                    l--;
            }
            while(v[j] ==v[j+1]) j++;
        }
        while(v[i] ==v[i+1]) i++;
    }
    // */

    cout << "[";
    for(int i = 0 ; i < ans.size() ; i++) {
        cout << "[";
        for(int j = 0 ; j < 4 ; j++) 
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << "]";
    return 0;
}
/*
Input :
6 0
1 0 -1 0 -2 2
Output :
[[-2 -1 1 2 ][-2 0 0 2 ][-1 0 0 1 ]]

Input :
10 9
4 3 3 4 4 2 1 2 1 1
Output :
[[1 1 3 4 ][1 2 2 4 ][1 2 3 3 ]]
*/