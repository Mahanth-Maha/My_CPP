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
    cout << v[1] <<endl;
    */

    // OPTIMAL O(n)
    // /*
    int temp, max1 , max2 ;
    cin >> max1;
    for(int i = 1 ; i < n;i++){
        cin >> temp;
        if(temp >= max1 ) {
            max2 = max1;
            max1 = temp;
        } else if (temp > max2){
            max2 = temp;
        }
    }
    cout << max2 ;
    // */

    return 0;
}

/*

Input:
n = 7
A[] = {1, 2, 0, 3, 2, 4, 5}
Output:
4

Input:
10
5 44 35 23 11 65 6 88 93 53
Output:
88
*/