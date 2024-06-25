#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int main()
{
    int n;
    cin >> n;    
    vector<int> arr(n) ;
    for(int i = 0 ; i < n;i++) cin>> arr[i];
    
    //BRUTE : O(2n) Space = O(n)
    /*
    vector <int>temp;
    for(int i = 0 ; i< n;i++) if(arr[i] != 0) temp.emplace_back(arr[i]);
    for(int i = 0 ; i < temp.size();i++) arr[i] = temp[i];
    for(int i = temp.size(); i< n ; i++) arr[i] = 0;

    */

    // OPTIMAL : Time = O(n) space = O(1)
    // /*
    int j = 0;
    for(int i = 0 ; i< n;i++){
        if(arr[i] != 0){
            arr[j++] = arr[i];
        }
    }
    while(j < n)
        arr[j++] = 0;
    // */
    for(int i = 0 ; i < n;i++) cout << arr[i] << " ";
    return 0;
}


/*
Input :(n,d,arr)
12
2 0 4 0 0 11 5 0 3 44 55 62
Output :
2 4 11 5 3 44 55 62 0 0 0 0
*/