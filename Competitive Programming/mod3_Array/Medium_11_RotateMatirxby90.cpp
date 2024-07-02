#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given a matrix  your task is to rotate the matrix 90 degrees clockwise.
*/

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n ,vector<int>(n));
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) cin >> matrix[i][j] ;

    // BRUTE :   Time = O(n^2)   Space = O(n^2)
    /*
    vector<vector<int>> ans(n, vector<int> (n,0));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            ans[j][n-i-1] = matrix[i][j] ;
        }
    }
    matrix = ans;
    */


    // OPTIMAL :   Time = O(n^2)   Space = O(1)
    // /*
    // Transpose
    for(int i = 0 ; i < n; i++){
        for(int j = i+1 ; j < n; j++){
            /*
            int temp = matrix[i][j] ;
            matrix[i][j] = matrix[j][i] ;
            matrix[j][i] = temp ;
            */
           // OR
           swap(matrix[i][j] , matrix[j][i]);
        }
    }
    // Flip - Reverse
    for(int i = 0 ; i < n; i++){
        /*
        for(int j = 0 ; j < n/2; j++){
            int temp = matrix[i][j] ;
            matrix[i][j] = matrix[i][n-1-j] ;
            matrix[i][n-1-j] = temp ;
        }
        */
    // OR
        reverse(matrix[i].begin(),matrix[i].end());
    }
    // */

    for(int i = 0 ; i < n ; i++){ for(int j = 0 ; j < n ; j++) 
        cout << matrix[i][j] << " "; 
        cout <<endl;
    }
    return 0;
}
/*
Input :
3
1 2 3 
4 5 6 
7 8 9
Output :
7 4 1 
8 5 2 
9 6 3
Input :
4
5 1 9 11 
2 4 8 10
13 3 6 7 
15 14 12 16
Output :
15 13 2 5 
14 3 4 1 
12 6 8 9 
16 7 10 11
*/