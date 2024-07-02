#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

/*
You are given an array of ‘N’ integers. You need to find the length of 
the longest sequence which contains the consecutive elements.
*/

bool ls(vector<int>& v,int d){
    for(int i = 0 ; i < v.size();i++)
        if(v[i] == d) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    int clen = 0;

    // BRUTE :   Time = O(n*n)   Space = O(1)
    /*
    for(int i = 0 ; i < n; i++){
        int c = 1;
        while(ls(v,v[i]+c)) 
            c++;
        clen = max(clen,c);
    }    
    */


    // BETTER :   Time = O(nlogn + n)   Space = O(1)
    // /*
    // sort(v.begin(),v.end());
    // int c = 1 ;
    // for(int i = 1 ; i < n; i++){
    //     if(v[i-1] != v[i]) 
    //         c = (v[i-1] + 1 == v[i]) ? c+1:1;
    //     clen = max(clen,c);
    // }
    // */


    // OPTIMAL :   Time = O(n + 2n at max) -> best : n to worst : nlogn  Space = O(n)
    // /* TRICK : find start of seq
    unordered_set<int> s;
    for(auto &i: v) s.insert(i);
    for(auto &i: v){
        if(s.find(i-1) == s.end()){
            int c = 1;
            while(s.find(i + 1)!=s.end())
                c++;
            clen = max(clen,c);
        }
    }
    // */

    cout << clen ;
    return 0;
}
/*
Input :
6
100 200 1 3 2 4
Output :
4
Input :
5
3 8 5 7 6
Output :
4
*/