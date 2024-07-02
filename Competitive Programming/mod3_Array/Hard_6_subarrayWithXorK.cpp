#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Given an array of integers A and an integer B. 
Find the total number of subarrays having bitwise XOR of all elements equal to k.
*/

int main()
{
    int n, B;
    cin >> n >> B;
    vector<int> A(n);
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    int maxXorK = 0;

    // BRUTE :   Time = O(n^3)   Space = O(1)
    /*
    for(int i = 0 ; i< n; i++){
        for(int j = i ; j< n; j++){
            int sum = 0;
            for(int k = i ; k<=j ; k++){
                sum = sum^A[k];
            }
            if(sum == B) maxXorK++;
        }
    }
    */


    // BETTER :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0 ; i< n; i++){
        int sum = 0;
        for(int j = i ; j< n; j++){
            sum ^= A[j];
            if(sum == B) 
                maxXorK++;
        }
    }
    */

    // OPTIMAL :   Time = O()   Space = O()
    // /*
    int x = 0;
    unordered_map<int,int> m;
    m[x] = 1;
    for(int i = 0 ; i< n; i++){
        x ^= A[i];
        m[x]++;
        maxXorK += m[x ^ B];
    }
    // */

    cout << maxXorK;
    return 0;
}
/*
Input :
5 6 
4 2 2 6 4
Output :
4

Input :
5 5
5 6 7 8 9
Output :
2

Input :
14 4
5 6 7 8 8 9 0 1 8 2 4 3 4 8 
Output :
6
*/