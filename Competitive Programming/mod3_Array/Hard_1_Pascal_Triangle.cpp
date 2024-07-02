#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
Pascal’s triangle:

Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
*/

/**************** NCR *****************/
// BRUTE : Time = O(n + n-r + r) = O(2n) Space = O(n) [stack]
long long factorial(long long n){
    if(n <= 1) return 1;
    return factorial(n-1)*n;
}
long long ncr(long long n, long long r){
    return factorial(n) /( factorial(n-r) * factorial(r) );
}


int main()
{
    

    // Variation 1 
    // Print the element at position (r, c) in Pascal’s triangle.
    // /*
    int r,c;
    cin >> r >> c ;
    // BRUTE :   Time = O(n)   Space = O(n)
    /* 
    cout << ncr(r-1,c-1) << endl;
    */
    
    // OPTIMAL :   Time = O(n)   Space = O(1)
    int res = 1;
    for(int i  = 0 ; i < c-1 ; i++){
        res *= (r-1 - i);
        res /= (i+1);
    }
    cout << res << endl;
    // */


    // Variation 2 
    // Print the n-th row of Pascal’s triangle.
    int nr;
    cin >> nr;
    
    // BRUTE :   Time = O(n^2)   Space = O(n)
    /*
    for(int i = 0 ; i < nr; i++){
        cout << ncr(nr-1,i) << " ";
    }
    cout << endl;
    */
    // OPTIMAL :   Time = O(n)   Space = O(1)
    // /*
    int temp = 1;
    for(int i = 0 ; i< nr ; i++){
        cout << temp << " " ;
        temp *= (nr-1-i);
        temp /= (i+1);
    }
    cout << "\n";
    // */


    // Variation 3 
    // Print the first n rows of Pascal’s triangle. 
    int n;
    cin >> n;
    /* 
    //BRUTE :   Time = O(n^3)   Space = O(n)
    for(int i = 0; i<n;i++){
        for(int r = 0 ; r <= i; r++){
            cout << ncr(i,r) << " ";
        }
        cout << endl;
    }
    */
    //OPTIMAL :   Time = O(n^2)   Space = O(1)
    // /* 
    for(int i = 0 ; i < n ; i++){
        int temp = 1;
        for(int r = 0 ; r < i+1 ; r++){
            cout << temp << " ";
            temp *= (i-r);
            temp /= (r+1);
        }
        cout << endl;
    }
    // */ 

    return 0;
}
/*
Input :
5 3
5
5
Output :
6
1 4 6 4 1
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/