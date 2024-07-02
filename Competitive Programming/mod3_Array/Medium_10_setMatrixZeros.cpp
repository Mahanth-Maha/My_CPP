#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given a matrix if an element in the matrix is 0 then 
you will have to set its entire column and row to 0 and then return the matrix.
*/

int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> v(m ,vector<int>(n));
    for(int i = 0 ; i < m ; i++) for(int j = 0 ; j < n ; j++) cin >> v[i][j] ;

    // BRUTE :   Time = O(m*n*max(m,n))   Space = O(m*n)
    /*
    vector<vector<int>> ans(m ,vector<int>(n,-1));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++) {
            if(!v[i][j]){
                for(int k = 0 ; k < n; k++){
                    ans[i][k] = 0 ;
                }
                for(int k = 0 ; k < m; k++){
                    ans[k][j] = 0 ;
                }
            }
            if(ans[i][j] != 0) 
                ans[i][j] = v[i][j];
        }
    }
    v = ans;
    */


    // BETTER :   Time = O(3 * n*m)   Space = O(n + m)
    /*
    vector<int> rows(m,0), cols(n,0);
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++) {
            if(!v[i][j]){
                rows[i] = cols[j] = 1;
            }
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        if(rows[i]){
            for(int j = 0 ; j < n ; j++)
                v[i][j] = 0;
        }
    }
        
    for(int j = 0 ; j < n ; j++) {
        if(cols[j]){
        for(int i = 0 ; i < m ; i++)
                v[i][j] = 0;
        }
    }
    */


    // OPTIMAL :   Time = O(2*n*m + 2*n + 2*m)   Space = O(1)
    // /* USE MATRIX itself as extra space
    
    /* Version 1 
    int r = 0, c = 0;
    for(int i = 0 ; i < m ; i++) if(v[i][0] == 0) r = 1;
    for(int j = 0 ; j < n ; j++) if(v[0][j] == 0) c = 1;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++) {
            if(v[i][j] == 0){
                v[i][0] = v[0][j] = 0;
            }
        }
    }
    for(int i = 1 ; i < m ; i++){
        for(int j = 1 ; j < n ; j++) {
            if(v[i][0] == 0 || v[0][j] == 0){
                v[i][j] = 0;
            }
        }
    }

    if(r) for(int i = 0 ; i < m ; i++)v[i][0] = 0;
    if(c) for(int j = 0 ; j < n ; j++)v[0][j] = 0;
    */

    // /* Version 2 :: Time = O(2*n*m + n + m)   Space = O(1)
    int col0 = 1;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++) {
            if(v[i][j] == 0){
                v[i][0] = 0;
                if(j != 0){
                    v[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1 ; i < m ; i++){
        for(int j = 1 ; j < n ; j++) {
            if(v[i][j] !=0 && (v[i][0] == 0 || v[0][j] == 0))
                v[i][j] = 0;
        }
    }
    if(v[0][0] == 0) for(int j = 0 ; j < n; j++) v[0][j] = 0;
    if(col0 == 0) for(int i = 0 ; i < m; i++) v[i][0] = 0;
    // */

    for(int i = 0 ; i < m ; i++){ 
        for(int j = 0 ; j < n ; j++) 
            cout << v[i][j] << " "; 
        cout <<endl;
    }
    return 0;
}
/*
Input :
3 3
1 1 1
1 0 1 
1 1 1 
Output :
1 0 1 
0 0 0 
1 0 1

Input :
3 4
0 1 2 0 
3 4 5 2 
1 3 1 5
Output :
0 0 0 0 
0 4 5 0 
0 3 1 0
*/