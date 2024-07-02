#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 Given an array that contains both negative and positive integers, 
 find the maximum product subarray.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    int maxPro = INT_MIN;
    // BRUTE :   Time = O(n^3)   Space = O(1)
    /*
    for(int i = 0 ; i<n;i++){
        for(int j = i+1 ; j<n;j++){   
            int pro = 1;
            for(int k = i ; k<=j;k++){
                pro *= v[k];
            }
            maxPro = max(pro, maxPro);
        }
    }
    */


    // BETTER :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0 ; i<n;i++){
        int pro = 1;
        for(int j = i+1 ; j<n;j++){   
            pro *= v[j];
            maxPro = max(pro, maxPro);
        }
    }
    */


    // OPTIMAL :   Time = O()   Space = O()
    // /*
    int prePro = 1, sufPro = 1;
    for (int i = 0; i < n; i++){
        
        prePro *= v[i];
        if (prePro == 0) prePro = 1;

        sufPro *= v[n - 1 - i];
        if (sufPro == 0) sufPro = 1;
        
        maxPro = max(max(maxPro, sufPro), prePro);
    }
    // */

    cout << maxPro;
    return 0;
}
/*
Input :
6
1 2 3 4 5 0
Output :
120

Input :
6
1 2 -3 0 -4 -5
Output :
20
*/