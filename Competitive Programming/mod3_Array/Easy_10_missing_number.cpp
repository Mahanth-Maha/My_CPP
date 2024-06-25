#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    // Brute O(n) Space O(n)
    /*
    vector<bool> check(n,false);
    for(int i = 0 ; i < n; i++){
        check[arr[i]] = true;
    }
    for(int i = 0 ; i < n; i++){
        if(check[i] == false) {
            cout << i;
            break;
        }
    }
    */

    // Optimal 1 : SUM Time = O(n) space = O(1)
    /*
    int sum_all = 0 ; 
    for(int i = 0 ;i < n; i++) 
        sum_all += arr[i];
    cout << ((n*(n+1)) / 2 ) - sum_all ;

    */
        
    // OPTIMAL 2 : XOR Time = O(n) space = O(1) 
    /* Working ::
        A = [ 1, 2, 3, 5]    
        xor1 = 1 ^ 2 ^ 3 ^ 4 ^ 5
        xor2 = 1 ^ 2 ^ 3 ^ 5
        since  a ^ a = 0 & a ^ 0 = a
        xor1 ^ xor2  = (1 ^ 1) ^ (2 ^ 2) ^ (3 ^ 3) ^ 4 ^ (5 ^ 5)
                    = 0 ^ 0 ^ 0 ^ 4  ^ 0 = 4 // ANS
    */
    // /*  BEST than sum
    int xor1 = n, xor2 = 0;
    for(int i = 0 ; i < n ; i++){
        xor1 = xor1 ^ i;
        xor2 = xor2 ^ arr[i];
    }
    cout << (xor1 ^ xor2) ;
    // */


    return 0;
}

/*
input : 
9
5 3 7 8 1 2 9 4 0
Output:
6
*/