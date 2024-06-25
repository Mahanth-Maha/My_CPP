#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];

    int temp = a[0];
    for(int i = 1 ; i < n ;i++) a[i-1] = a[i] ;
    a[n-1] = temp;

    for(int i = 0 ; i < n ;i++) cout << a[i] << " ";

    return 0;
}

/*
Input :
8
2 4 11 5 3 44 55 62
Output : 
4 11 5 3 44 55 62 2
*/