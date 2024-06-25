#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(nlogn * n)   Space = O(n)
    /*
    map<int, int> mp;
    for(int i = 0 ; i <n;i++){
        if(mp.find(v[i]) == mp.end())
            mp[v[i]] = 1;
        else
            mp[v[i]]++;
    }
    for(auto &i : mp)
        if(i.second == 1) {
            cout << i.first ;
            break;
        }
    */

    // OPTIMAL :   Time = O(n)   Space = O(1)
    // /*
    int x = 0;
    for(int i = 0 ; i < n; i++){
        x ^= v[i];
    }
    cout << x;
    // */

    return 0;
}
/*
Input :
5
2 1 4 4 2
Output :
1
Input :
7
6 3 3 7 4 7 6
Output :
4
*/