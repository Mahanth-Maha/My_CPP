#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
You are given an array of prices where prices[i] is the price of a 
given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock. 
Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0 ; i < n ; i++) cin >> prices[i] ;

    int maxprofit = 0;
    // BRUTE :   Time = O()   Space = O()
    /*
    for(int i = 0 ; i <n ; i++){
        for(int j = i+1 ; j <n ; j++){
            if(prices[i] < prices[j])
                maxprofit = max(maxprofit, prices[j] - prices[i]);
        }
    }
    */


    // OPTIMAL :   Time = O(n)   Space = O(1)
    // /*
    int minimal = INT_MAX ;
    for(auto &i : prices){
        maxprofit = max(i - minimal , maxprofit);
        minimal = min( minimal , i);
    }
    // */

    cout << maxprofit ;
    return 0;
}
/*
Input :
6
7 1 5 3 6 4
Output :
5

Input :
5
7 6 4 3 1
Output :
0
*/