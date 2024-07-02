#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Given an array of integers and an integer k, 
return the total number of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    int subArrays = 0;

    // BRUTE :   Time = O(n^3)   Space = O(1)
    /*
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            int s = 0;
            for(int  p = i ; p <= j ; p++){
                s += v[p];
            }
            if(s == k) subArrays++;
        }
    }
    */


    // BETTER :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0 ; i < n; i++){
        int s = 0;
        for(int j = i ; j < n; j++){
            s += v[j];
            if(s == k) 
                subArrays++;
        }
    }
    */


    // OPTIMAL :   Time = O(nlogn)   Space = O(n)
    // /*
    unordered_map<int,int> m;
    int prefix =0;
    m[0] = 1;
    for(auto &i : v){
        prefix += i;
        // if(m.find( prefix - k ) != m.end())
        subArrays += m[prefix - k];
        m[prefix]++;
    }
    // */

    cout <<subArrays ;
    return 0;
}
/*
Input :
4 6
3 1 2 4 
Output :
2

Input :
3 3
1 2 3
Output :
2
*/