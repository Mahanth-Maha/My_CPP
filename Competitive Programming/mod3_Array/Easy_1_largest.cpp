#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int  n;
    cin >> n;
    // Brute  : O(nlogn)
    /*
    vector<int> v(n);
    for(int i = 0 ; i < n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    cout << v[0] <<endl;
    */

    // BETTER O(n)
    /*
    int temp, maxi = INT_MIN;
    for(int i = 0 ; i < n;i++){
        cin >> temp;
        maxi = (temp > maxi) ? temp : maxi;
    }
    cout << maxi ;
    */

   // OPTIMAL 
    vector<int> v(n);
    for(int i = 0 ; i < n;i++){
        cin >> v[i];
    }
    cout << * max_element(v.begin(),v.end()) ;

    return 0;
}

/*

Input:
n = 7
A[] = {1, 2, 0, 3, 2, 4, 5}
Output:
5
*/