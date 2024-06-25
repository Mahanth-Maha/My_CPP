#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];

    //Brute O(n * d) in worst case : d%n == n O(n^2)
    /*
    d = d%n;
    for(int j = 0 ; j < d ; j++){
        int temp = a[n-1];
        for(int i = n-2; i >= 0 ;i--) a[i+1] = a[i] ;
        a[0] = temp;
    }
    */

    //Better O(n + d) == O(n) with O(d) space 
    /*    
    d = d%n;
    vector<int> v(d);
    for(int i = n-d ; i<n ; i++ )
        v[i - n + d] = a[i];
    for(int i = n-1 ; i >= d ; i--)
        a[i] = a[i-d];
    for(int i = 0; i < d ; i++ )
        a[i] = v[i];
    */

    // OPTIMAL : O(2 * n) == O(n)  with O(1) space
    // /*
    d = d%n;
    //2 4 11 5 3 44 55 62 d=3
    reverse(a.begin(),a.end()-d );
    //11 4 2 | 5 3 44 55 62 d=3
    reverse(a.end()-d,a.end());
    //11 4 2 | 62 55 44 3 5 d=3
    reverse(a.begin(),a.end());
    //5 3 44 55 62 2 4 11 d=3 -> output
    // */

    for(int i = 0 ; i < n ;i++) cout << a[i] << " ";

    return 0; 
}

/*
Input :(n,d,arr)
8 3
2 4 11 5 3 44 55 62
Output :
44 55 62 2 4 11 5 3
Input :(n,d,arr)
8 498
62 44 21 35 63 47 59 63
Output :
21 35 63 47 59 63 62 44
*/