#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n,ans = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // OPTIMAL :   Time = O()   Space = O()
    // /*
    int temp = 0;
    for (int i = 0; i < n; i++){
        if(v[i] == 1) 
            ans = max(++temp,ans);
        else 
            temp = 0 ;
    }
    // */

    cout << ans;
    // for(int i = 0 ; i < n ; i++) cout << v[i] ;
    return 0;
}
/*
Input :
20
0 1 0 1 1 1 0 0 0 1 0 1 1 1 1 1 0 0 1 0
Output :
5
*/