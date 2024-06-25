#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    // BRUTE :   Time = O(nlogn)   Space = O(1)
    /*
    sort(v.begin(),v.end());
    */


    // BETTER :   Time = O(2n)   Space = O(1)
    /*
    int i = 0,j = 0;
    while(j<n){
        if(v[j] == 0){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
        j++;
    }
    j = i;
    while(j<n){
        if(v[j] == 1){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
        j++;
    }
    */


    // BETTER 2 :   Time = O(2n)   Space = O(1)
    /*
    int i = 0, j =0 , k = 0;
    for(int p = 0 ; p < n; p++){
        if(v[p] == 0) i++;
        else if(v[p] == 1) j++;
        else if(v[p] == 2) k++;
    }
    int t=0;
    while(i-- > 0) v[t++] = 0;
    while(j-- > 0) v[t++] = 1;
    while(k-- > 0) v[t++] = 2;
    */

    // OPTIMAL :   Time = O(n)   Space = O(1)
    // /*
    int low = 0 ,high = n-1, mid = 0;
    while(mid <= high){
        if(v[mid] == 0){
            int temp = v[mid];
            v[mid++] = v[low];
            v[low++] = temp;
        }
        else if(v[mid] == 1){
            mid++;
        } else if(v[mid] == 2){
            int temp = v[high];
            v[high--] = v[mid];
            v[mid] = temp;
        }
    }
    // */


    for(int i = 0 ; i < n ; i++) cout << v[i] << " ";
    return 0;
}
/*
Input :
9
2 1 1 2 1 1 0 0 0 
Output :
0 0 0 1 1 1 1 2 2 
Input :
10
1 1 1 1 1 0 0 0 0 0 
Output :
0 0 0 0 0 1 1 1 1 1 
*/