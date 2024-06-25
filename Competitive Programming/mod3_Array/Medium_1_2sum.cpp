#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    int sum1 = 0 , sum2 = 0;

    bool answer = false;
    // BRUTE :   Time = O(n^2)   Space = O(n^2)
    /*
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(v[i] + v[j] == t) { 
                answer = true;
                sum1 = i;
                sum2 = j;
                break;
            }
            if(answer == true) break;
        }
        if(answer == true) break;
    }
    */


    // BETTER :   Time = O(n)   Space = O(n)
    /*
    unordered_map<int,int> temp;
    for(int i = 0 ; i <n;i++){
        if(temp.find(v[i]) != temp.end()){
            sum2 = i;
            sum1 = temp[v[i]];
            answer = true;
            break;
        }else{
            temp[t - v[i]] = i ;
        }
    }
    */

    // OPTIMAL :   Time = O(N log N)   Space = O(1)
    // /*
    // DOESN'T WORKS FOR INDEXES, NOT OPTIMAL, ONLY OPTIMAL FOR YES/NO TYPE;
    sort(v.begin(),v.end());
    int i = 0, j = n-1;
    while(i < j){
        if(v[i] + v[j] < t){
            i++;
        } else if(v[i] + v[j] > t){
            j--;
        } else {
            answer = true;
            break;
        }
    }

    // */

    // for(int i = 0 ; i < n ; i++) cout << v[i] << " ";
    (answer) ?cout << "YES\n" << sum1 << " " << sum2 : cout << "NO" ;
    return 0;
}

/*

Input :
5 14
2 6 5 8 11
Output :
YES
1 3

Input :
5 15
2 6 5 8 11
Output :
NO

*/