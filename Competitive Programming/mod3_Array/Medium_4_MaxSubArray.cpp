#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given an integer array arr, find the contiguous sub array (containing at least one number) 
which has the largest sum and returns its sum and prints the sub array.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    int maxsum = INT_MIN;

    // BRUTE :   Time = O(n^3)   Space = O(1)
    /*
    for(int i = 0 ; i <n ;i++){
        for(int j = 0 ; j<n ;j++){
            int temp = 0;
            for(int p = i ; p <= j ;p++){
                temp += v[p];
            }
            maxsum = max(temp,maxsum);
        }
    }
    */


    // BETTER :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0 ; i <n ;i++){
        int temp = 0;
        for(int j = i ; j<n ;j++){
            temp += v[j];
            maxsum = max(temp,maxsum);
        }
    }
    */


    // OPTIMAL :   Time = O()   Space = O()
    // KADANE's Algorithm
    // /*
    int temp = 0;
    for(int i = 0 ; i < n;i++){
        temp += v[i];
        maxsum = max(maxsum, temp);
        if(temp < 0){
            temp = 0;
        }
    }
    // */

    cout <<maxsum ;
    return 0;
}
/*
Input :

Output :

*/