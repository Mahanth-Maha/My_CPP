#include "../display.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
Given an array of numbers, you need to return the count of reverse pairs. 
Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
*/

int count_reverse_pairs(vector<int> &arr, int low, int high, vector<int> &temp){
    int count = 0 ;
    if(low >= high) return count;
    int mid = (low+high)/2;
    count += count_reverse_pairs(arr,low,mid, temp);
    count += count_reverse_pairs(arr,mid+1,high, temp);

    int j = mid + 1, k = 0;
    for(int i = low; i <= mid ; i++){
        while(j <=high && arr[i] > 2*arr[j]) j++;
        count += (j- (mid+1));
    }

    int i = k = low;
    j = mid +1;
    for(int p = low ; p <= high ; p++) temp[p] = arr[p];
    while(i <= mid && j <= high)
        if(arr[i] < arr[j]) arr[k++] = temp[i++];
        else arr[k++] = temp[j++];
    while(i <= mid)
        arr[k++] = temp[i++];
    while(j <= high)
        arr[k++] = temp[j++];

    return count;
}


int main()
{
    int n , count;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i] ;

    // BRUTE :   Time = O(n^2)   Space = O(1)
    /*
    for(int  i = 0 ; i < n; i++){
        for(int  j = i+1 ; j < n; j++){
            if(arr[i] >( 2* arr[j])) 
                count++;
        }
    }
    */


    // OPTIMAL :   Time = O(nlogn)   Space = O(n)
    // /*
    vector<int> vec = arr , temp(n);
    count = count_reverse_pairs(arr, 0 , n-1 , temp);
    // */

    cout << count;
    return 0;
}
/*
Input :
5
1 3 2 3 1
Output :
2

Input :
4
3 2 1 4 
Output :
1

*/