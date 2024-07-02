#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
You are given a read-only array of N integers with values also in the range [1, N] 
both inclusive. Each integer appears exactly once except A which appears twice 
and B which is missing. The task is to find the repeating and missing numbers A and B 
where A repeats twice and B is missing.
*/

int main()
{
    int n,A=0,B=0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE 1 :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0 ; i < n+1; i++){
        int cnt = 0;
        for(int j = 0 ; j < n; j++)
            if(i == v[j])
                cnt++;
        if(cnt == 2) A = i;
        if(cnt == 0) B = i;
    }
    */
    
    
    // BRUTE 2 :   Time = O(n)   Space = O(n)
    /*
    vector<int> vis(n+1,0);
    for(int i = 0 ; i < n; i++){
        vis[v[i]]++;
    }
    for(int i = 1 ; i < n+1; i++){
        if(vis[i] == 0) B = i;
        if(vis[i] == 2) A = i;
    }
    */


    // BETTER :   Time = O(nlogn)   Space = O(1)
    /*
    sort(v.begin(),v.end());
    int values = 0;
    for(int i = 0 ; i < n; i++){
        if(i!= n-1 && v[i] == v[i+1])  A = i+1;
        if(values + 1 == v[i]) values++;
    }
    B = values +1;
    */


    // OPTIMAL 1 :   Time = O(n)   Space = O(1)
    /*
    int s = 0 , sq = 0, sn = (n*(n+1))/2, sqn = (n*(n+1)*(2*n+1) )/ 6 ;
    for(auto&i : v) {
        s+= i;
        sq += i*i;
    }
    // B   - A      = Sn - s
    // B^2 - A^2    = S^2n - s^2         system of equations
    B = ((sn - s) + ((sqn - sq)/(sn-s))) / 2;
    A = B - (sn - s);
    
    */
    
    
    // OPTIMAL 2 :   Time = O(N)   Space = O(1)
    // /*
    int x = 0 ; 
    for(int i = 0 ; i < n; i++){
        x ^= i+1;
        x ^= v[i];
    }
    int bit = 1;
    while((bit & x )== 0) {
        bit *=2;
    }
    int a = 0 ,b = 0;
    for(int i = 0 ; i < n ; i++){
        if((i+1) & bit) a ^= (i+1);
        else b ^=(i+1); 
        if(v[i] & bit) a ^= v[i];
        else b ^=v[i];
    }
    int cnt = 0;
    for(auto &i :v) if(a == i) cnt++;
    if(cnt == 2) {A = a; B =b;}
    else if(cnt == 0) {A = b; B = a;}
    // */

    cout << A << " "<< B << " ";
    return 0;
}
/*
Input :
5
3 1 2 5 3
Output :
3 4

Input :
7
3 1 2 5 4 6 7 5
Output :
5 3

*/