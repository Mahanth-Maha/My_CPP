#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
Merge them in sorted order. Modify arr1 so that it contains the first N elements 
and modify arr2 so that it contains the last M elements.
*/

int main()
{
    int n , m;
    cin >> n>> m;
    vector<int> arr1(n), arr2(m);
    for(int i = 0 ; i < n ; i++) cin >> arr1[i] ;
    for(int i = 0 ; i < m ; i++) cin >> arr2[i] ;

    // OPTIMAL 1 :   Time = O(nlogn)   Space = O(1)
    /*
    int i = 0 , j =0;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else {
            int temp = arr1[i];
            arr1[i] = arr2[j];
            int k = j;
            while(k  < m && temp > arr2[k+1]){
                arr2[k] = arr2[k+1];
                k++;
            }
            if(k == m) k--;
            arr2[k] = temp;
            i++;
        }
    }
    */


    // OPTIMAL 2 :   Time = O(nlogn)   Space = O(1)
    // /*
    int i = n-1 , j =0;
    while(i >= 0  && j < m){
        if(arr1[i] > arr2[j]){
            int temp = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = temp;
            i--;
            j++;
        } else break;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    // */


    if(arr1.size() == n)
    for(int i = 0 ; i < n ; i++) cout << arr1[i] << " ";
    if(arr2.size() == m)
    for(int i = 0 ; i < m ; i++) cout << arr2[i] << " ";
    return 0;
}
/*
Input :
4 6
9 1 5 3
2 4 6 8 7
Output :
1 2 3 4 5 6 7 8 9

Input :
4 6
9 1 5 3
2 4 6 8 7
Output :
1 2 3 4 5 6 7 8 9
*/