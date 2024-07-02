#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given an array of N integers, count the inversion of the array (using merge-sort).
inversion of an array - Definition: for all i & j < size of array, 
if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].
*/

int count_inversions(vector<int> &arr, int low, int high, vector<int> &temp ){
    int inversions = 0;
    if(low >= high) return inversions;
    int mid = (low + high )/2;
    inversions += count_inversions(arr,low , mid, temp);
    inversions += count_inversions(arr,mid+1,high, temp);
    
    for(int i= low; i <= high; i++) 
        temp[i] = arr[i];

    int i = low , j = mid + 1, k = low;
    while(i <= mid && j <= high){
        if(temp[i] > temp[j]){
            inversions += mid + 1 - i;
            arr[k++] = temp[j++] ;
        } else  {
            arr[k++] = temp[i++] ;
        }
    }
    while( i <= mid){
        arr[k++] = temp[i++];
    }
    while( j <= high){
        arr[k++] = temp[j++];
    }
    return inversions;
}


int main()
{
    int n, inversions  = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;

    // BRUTE :   Time = O(n^2)   Space = O(1)
    /*
    for(int  i = 0 ; i < n; i++){
        for(int  j = i+1 ; j < n; j++){
            if(arr[i] > arr[j]) inversions++;
        }
    }
    */

    // OPTIMAL :   Time = O(nlogn)   Space = O(n)
    // /*
    vector<int> v = arr, temp(n);
    inversions = count_inversions(v, 0,n-1, temp);
    // */

    cout << inversions ;
    return 0;
}
/*
Input :
5
1 2 3 4 5
Output :
0

Input :
5
5 4 3 2 1
Output :
10
*/