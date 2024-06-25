#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
Without altering the relative order of positive and negative elements, 
you must return an array of alternately positive and negative values.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(2n)   Space = O(n)
    /*
    vector<int> pos,neg;
    for(auto &i : v)
        if(i < 0) neg.push_back(i);
        else pos.push_back(i);
    for(int i = 0 ; i < n; i++)
        if(i %2 == 0) v[i] = pos[i/2];
        else v[i] = neg[i/2];
    */


    // BETTER :   Time = O(n)   Space = O(n)
    // /*
    int pos = 0,neg = 1;    
    vector<int> ans(n);
    for(int i = 0 ; i < n ; i++){
        if(v[i] > 0){
            ans[pos] = v[i];
            pos += 2;
        } else {
            ans[neg] = v[i];
            neg += 2;
        }
    }
    v.clear();
    v= ans;
    // */


    // OPTIMAL :   Time = O()   Space = O()
    // /*
    
    // */

    for(int i = 0 ; i < n ; i++) cout << v[i] << " ";
    return 0;
}
/*
Input :
4
1 2 -4 -5
Output :
1 -4 2 -5

Input :
6
1 2 -3 -1 -2 3
Output :
1 -3 2 -1 3 -2
*/