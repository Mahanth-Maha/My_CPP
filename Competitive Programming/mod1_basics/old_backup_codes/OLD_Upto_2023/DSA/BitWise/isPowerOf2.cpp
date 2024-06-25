#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

bool isPowerOf2_1(int n){
    int ones = 0;
    if(n <= 0) return false;
    while(n){
        n = (n&(n-1));
        ones++;
    }
    return (ones == 1) ? true:false;
}

// Kernigans Algo
bool isPowerOf2_2(int n){
    if(n <= 0) return false;
    return ((n & (n-1)) == 0);
}

// Kernigans Algo + single liner
bool isPowerOf2_3(int n){
    return (n && ((n & (n-1)) == 0));
}

int main()
{
    int  T,n;
    cin >> T;
    while(T--){
        cin >> n;
        // cout << isPowerOf2_1(n) << endl;
        // cout << isPowerOf2_2(n) << endl;
        cout << isPowerOf2_3(n) << endl;
    }

    return 0;
}