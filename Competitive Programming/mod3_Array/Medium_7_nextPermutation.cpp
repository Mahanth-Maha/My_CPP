#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given an array Arr[] of integers, rearrange the numbers of the given array into 
the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the 
lowest possible order (i.e., sorted in ascending order).

*** Find next lexicographically greater permutation ***

*/


// NOTES : hint - longest prefix matches for next permutation

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



int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(n* n!)   Space = O(n + n!)
    /*
    vector<vector<int>> permutes;
    vector<int> vis(n,0) , v_copy =v , v2 = v;
    sort(v_copy.begin(),v_copy.end());
    all_permute(v_copy,vis,permutes,{});
    int found = 0,last = 0;
    for(auto &i : permutes){
        if(found){ 
            v = i;
            break;
        }
        if(v == i) {
            found = 1;
        }
    }
    if(v2 == v)
        sort(v.begin(),v.end());
    */


    // BETTER :   Time = O()   Space = O()
    // /*
    // next_permutation(v.begin(),v.end());
    // */


    // OPTIMAL 1 :   Time = O(nlogn)   Space = O(n)
    /* Implementing the inbuilt function
    int i = n-1;
    while(i >=0 && v[i-1] > v[i]) i--;
    i--;
    if(i < 0) 
        sort(v.begin(),v.end()); 
    else{
        int  j = n-1;
        while(v[j] < v[i]) j--;
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        sort(v.begin()+i+1,v.end());
    }
    */
    
    
    // OPTIMAL 2 :   Time = O(n)   Space = O(n)
    // /* Implementing the inbuilt function
    int i = n-1;
    while(i >=0 && v[i-1] > v[i]) i--;
    i--;
    if(i < 0) 
        reverse(v.begin(),v.end());
    else{
        int  j = n-1;
        while(v[j] < v[i]) j--;
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        reverse(v.begin()+i+1,v.end());
    }
    // */


    for(int i = 0 ; i < n ; i++) cout << v[i] << " ";
    return 0;
}
/*
Input :
3
1 3 2
Output :
2 1 3

Input :
3
3 2 1
Output :
1 2 3
*/

