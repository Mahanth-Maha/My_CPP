#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Given an array containing both positive and negative integers,
we have to find the length of the longest subarray 
with the sum of all elements equal to zero.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    int maxSubArray = 0;
    // BRUTE :   Time = O(n^3)   Space = O(1)
    /*
    for(int i = 0 ; i< n; i++){
        for(int j = i ; j< n; j++){
            int sum = 0;
            for(int k = i ; k<=j ; k++){
                sum += v[k];
            }
            if(sum == 0) maxSubArray = max(maxSubArray , j - i + 1);
        }
    }
    */


    // BETTER :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0 ; i< n; i++){
        int sum = 0;
        for(int j = i ; j< n; j++){
            sum += v[j];
            if(sum == 0) maxSubArray = max(maxSubArray , j - i + 1);
        }
    }
    */


    // OPTIMAL :   Time = O()   Space = O()
    // /*
    unordered_map<int,int> m;
    int prefixSum = 0;
    for(int i = 0 ; i< n; i++){
        prefixSum = prefixSum + v[i];
        if(prefixSum == 0) maxSubArray = i+1;
        else{
            if(m.find(prefixSum) != m.end()){
                maxSubArray = max(maxSubArray, i - m[prefixSum]);
            } else 
                m[prefixSum] = i;
        }
    }
    // */

    cout <<maxSubArray;
    return 0;
}
/*
Input :
6
9 -3 3 -1 6 -5
Output : 5

Input :
8
6 -2 2 -8 1 7 4 -10
Output : 5

*/