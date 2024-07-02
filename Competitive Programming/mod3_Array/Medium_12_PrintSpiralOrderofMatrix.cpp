#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given a Matrix print the given matrix in spiral order.
*/

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n ,vector<int>(m));
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) cin >> matrix[i][j] ;

    vector<int> out;
    // one and only solution - Optimal
    // OPTIMAL :   Time = O()   Space = O()
    // /*
    
    int top = 0,bottom = n-1, left =0 ,right = m-1;
    while(top <= bottom && left <= right){
        for(int i = left ; i <= right ;i++ ) out.emplace_back(matrix[top][i]);
        top++;
        for(int i = top ; i <= bottom ;i++ ) out.emplace_back(matrix[i][right]);
        right--;
        if(top <= bottom){
            for(int i = right ; i >= left ;i--) out.emplace_back(matrix[bottom][i]);
            bottom--;
        }
        if(left <= right){
            for(int i = bottom ; i >= top ;i-- ) out.emplace_back(matrix[i][left]);
            left++;
        }
    }
    // */

    for(int i = 0 ; i < out.size(); i++) cout << out[i] << " "; 
    return 0;
}
/*
Input :
4 4
1 2 3 4 
5 6 7 8
9 10 11 12
13 14 15 16
Output :
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Input :
3 3
1 2 3
4 5 6 
7 8 9
Output :
1 2 3 6 9 8 7 4 5
*/