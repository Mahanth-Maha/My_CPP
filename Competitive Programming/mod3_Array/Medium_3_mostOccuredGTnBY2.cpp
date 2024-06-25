#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.
*/

int main()
{
    int n,ans;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(nlogn)   Space = O(1)
    /*
    sort(v.begin(),v.end());
    for(int i = 0;i<=n/2;i++){
        if(v[i] == v[i+n/2]){
            ans = v[i];
            break;
        }
    }
    */


    // BETTER :   Time = O(n+n)   Space = O(n)
    /*
    unordered_map<int,int> m;
    for(int i= 0 ; i < n;i++){
        m[v[i]]++;
    }
    int cnt = INT_MIN;
    for(auto &i : m){
        if(cnt < i.second ) {
            ans = i.first;
            cnt = i.second;
        }
    }
    */


    // OPTIMAL :   Time = O(N)   Space = O(1)
    // /*
    // MOORE's Voting Algorithm 
    int ele, c = 0 ;
    for(int i = 0 ; i < n; i++){
        if(c == 0)
            ele = v[i];
        if(v[i] == ele) c++;
        else c--;
    }
    c = 0;
    for(int i = 0 ; i < n; i++){
        if(ele == v[i]) c++;
    }
    if(c > n/2) ans = ele;
    else ans = -1;


    // */

    cout << ans ;
    return 0;
}
/*
Input :
10
4 4 2 4 3 4 4 3 2 4
Output :
4
Input :
7
2 2 1 1 1 2 2
Output :
2
*/