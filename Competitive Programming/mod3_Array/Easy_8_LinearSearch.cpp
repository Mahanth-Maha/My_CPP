#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int linear(vector<int>& v, int k){
for(int i = 0 ;i < v.size() ; i ++)
    if(v[i] == k) return i;
    return -1;
}

int main()
{
    int n,k;
    cin >> n >> k;    
    vector<int> arr(n) ;
    for(int i = 0 ; i < n;i++) cin>> arr[i];
    
    //OPTIMAL : O(n) Space = O(1)
    // /*
    // cout << linear(arr,k);
    // */

    return 0;
}


/*
Input :(n,d,arr)
12
2 0 4 0 0 11 5 0 3 44 55 62
Output :
2 4 11 5 3 44 55 62 0 0 0 0
*/