#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given an array, print all the elements which are leaders. 
A Leader is an element that is greater than all of the elements on its right side 
in the array.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n),leaders;
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(n^2)   Space = O(n+1)
    /*
    for(int i = 0 ; i < n;i++){
        int flag = 1;
        for(int j = i+1 ; j < n;j++){
            if(v[i] < v[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) leaders.push_back(v[i]);
    }
    */


    // OPTIMAL :   Time = O(n)   Space = O(n+1)
    // /*
    int lmax =  INT_MIN;
    for(int i = n-1; i >=0 ; i--){
        if(v[i] > lmax )
            leaders.insert(leaders.begin(), v[i]);
        lmax = max(lmax,v[i]);
    }
    // */

    for(int i = 0 ; i < leaders.size() ; i++) cout << leaders[i] << " ";
    return 0;
}
/*
Input :
4
4 7 1 0
Output :
7 1 0

Input :
6
10 22 12 3 0 6
Output :
22 12 6
*/