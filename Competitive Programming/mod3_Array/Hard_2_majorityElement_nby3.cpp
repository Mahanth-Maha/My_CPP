#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Given an array of N integers. Find the elements that appear more 
than N/3 times in the array. If no such element exists, return an empty vector.
*/
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    vector<int> ans;

    // BRUTE :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0 ; j  < n; j++)
            if(v[j] == v[i]) cnt++;
        if(cnt > n/3){ 
            int flag  = 1;
            for(auto &u: ans)
                if(u == v[i]) 
                    flag = 0;
            if(flag)
                ans.push_back(v[i]);
        }
    }
    */


    // BETTER :   Time = O(n)   Space = O(n)
    /*
    unordered_map<int,int> m;
    for(auto &i : v)
        m[i]++;
    for(auto &u : m)
        if(u.second > n/3) 
            ans.push_back(u.first);
    sort(ans.begin(),ans.end());
    */


    // OPTIMAL :   Time = O(n)   Space = O(1)
    // /*
    int c = 0 ;
    int c1 = 0, c2 = 0 , e1 = INT_MIN, e2  = INT_MIN;
    for(int i = 0 ; i < n; i ++){
        if(c1 == 0 && e2 != v[i]){
            c1++;
            e1 = v[i];
        } else if(c2 == 0 && e1 != v[i]){
            c2++;
            e2 = v[i];
        } else if(e1 == v[i]){
            c1++;
        } else if(e2 == v[i]){
            c2++;
        } else {
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for(int i = 0 ; i < n ; i++){
        if(v[i] == e1) c1++;
        else if(v[i] == e2) c2++;
    }
    if(c1 > n/3) ans.push_back(e1);
    if(c2 > n/3) ans.push_back(e2);
    // */

    sort(ans.begin(),ans.end());
    cout << "[";
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << " ";
    cout << "]";
    return 0;
}
/*
Input :
5
1 2 2 3 2
Output :
[2 ]

Input :
6
11 33 33 11 33 11
Output :
[11 33 ]

Input :
5
1 2 3 4 5
Output :
[]

*/