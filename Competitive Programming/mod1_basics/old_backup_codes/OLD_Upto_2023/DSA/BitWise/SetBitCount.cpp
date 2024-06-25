#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

int SetBitCount1(int n){
    int c = 0;
    while(n){
        if((n & 1)) c++;
        n = n >> 1;
    }
    return c;
}

// Kernigans Algo
int SetBitCount3(int n){
    int c = 0;
    while(n){
        c++;
        n = (n & (n-1));
    }
    return c;
}

// Memoization
int SetBitCount2(int n){
    int c = 0, dp[256];
    dp[0] = 0;
    for(int i = 1 ; i < 256;i++) dp[i] = dp[(i& (i-1))] + 1; 
    while(n){
        c += dp[ ( n & 255)];
        n = n >> 8;
    }
    return c;
}



int main()
{
    int  T,n;
    cin >> T;
    while(T--){
        cin >> n;
        // cout << SetBitCount1(n) << endl;
        // cout << SetBitCount2(n) << endl;
        cout << SetBitCount3(n) << endl;
    }

    return 0;
}