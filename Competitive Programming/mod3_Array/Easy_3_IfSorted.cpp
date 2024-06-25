#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int  n;
    cin >> n;
    // OPTIMAL O(n)
    // /*
    int temp ,prev , sorted = 1;
    cin >>prev;
    for(int i = 1 ; i < n;i++){
        cin >> temp;
        if(prev > temp) {
            sorted = 0;
            break;
        }
    }
    cout << sorted;
    // */

    return 0;
}

/*

Input:
7
1 2 0 3 2 4 5
Output:
0

Input:
10
15 34 35 43 51 55 66 68 72 93
Output:
1
*/