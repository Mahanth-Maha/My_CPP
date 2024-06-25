#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int main()
{
    int n, key;
    cin >> n;
    cin >> key;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int ans = 0;
    // BRUTE :   Time = O(n^3)   Space = O(1)
    /*
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            int s = 0;
            for(int  k = i; k < j ; k++){
                s += v[k];
            }
            if(s == key){
                ans = max(ans, j - i);
            }
        }
    }
    */

    // BETTER 1 :   Time = O(n^2)   Space = O(1)
    /*
    for(int i = 0 ; i < n; i++){
        int s = 0;
        for(int j = i ; j < n; j++){
            s += v[j];
            if(s == key){
                ans = max(ans, j - i + 1);
            }
        }
    }
    */

    // BETTER 2 :   Time = O(n^2)   Space = O(1)
    /*
    // Works only when there are no zeroes and negative numbers in ARR
    // map<int, int> prefix;
    unordered_map<int, int> prefix;
    prefix[v[0]] = 0;
    int pre_sum = v[0];
    if (v[0] == key)
        ans = 1;

    for (int i = 1; i < n; i++) {
        pre_sum += v[i];
        prefix[pre_sum] = i;
        if (pre_sum == key)
            ans = i + 1;
        if (prefix.find(pre_sum - key) != prefix.end())
            ans = max(ans, i - prefix[pre_sum - key]);
    }
    */
    
    
    // OPTIMAL 1 :   Time = O(n*1)   Space = O(n)
    //Time :: using unordered map : best = O(n) worst = O(n^2)
    //Time :: using map : O(n * log(n))
    // /*
    // BEST OPTIMAL when there is negatives and zeros
    unordered_map<int, int> prefix;
    prefix[v[0]] = 0;
    int pre_sum = v[0];
    if (v[0] == key)
        ans = 1;

    for (int i = 1; i < n; i++) {
        pre_sum += v[i];
        if (prefix.find(pre_sum) == prefix.end())
            prefix[pre_sum] = i;
        if (pre_sum == key)
            ans = i + 1;
        if (prefix.find(pre_sum - key) != prefix.end())
            ans = max(ans, i - prefix[pre_sum - key]);
    }

    // */ 

    // OPTIMAL 2 :   Time = O(n)   Space = O(1)
    // 2 pointer & greedy approach 
    // DOESN'T WORK IF THERE ARE NEGATIVE NUMBERS IN ARR    
    /*
    int i = 0, j = 0, sum = 0;
    while(i < n){
        if(sum > key){
            sum -= v[j];
            j++;
        } else if(sum == key){
            ans = max(ans , i-j);
            i++;
        } else {
            sum += v[i];
            i++;
        }
    }
    while(j<n){
        sum -= v[j];
        ans = max(ans , (i-1)-j);
        j++;
    }
    */

    cout << ans;
    return 0;
}
/*
Input :
3 5
2 3 5
Output :
2
Input :
5 10
2 3 5 1 9
Output :
3

Input :
4 3
2 0 0 3
Output :
3
// Negative numbers in arr
Input :
9 8
7 4 2 -3 5 1 -1 4 6  
Output :
6

Input :
3 1
-1 1 1
Output :
3

*/