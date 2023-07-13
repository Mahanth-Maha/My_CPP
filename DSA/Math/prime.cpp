#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#define LOG(x) std::cout << x << std::endl;

using namespace std;


// Naive
bool isPrime_v1(int n){
    if(n == 1) return false;
    for(int i = 2 ; i < n ; i++)
        if(!(n%i)) return false; 
    return true;
}


// upto square root
bool isPrime_v2(int n){
    if(n == 1) return false;
    for(int i = 2 ; i <= sqrt(n) ; i++)
        if(!(n%i)) return false;
    return true;
}


// upto square root better code
bool isPrime_v3(int n){
    if(n == 1) return false;
    for(int i = 2 ; i * i <= n ; i++)
        if(!(n%i)) return false;
    return true;
}

// further Optimization
bool isPrime_v4(int n){
    if(n == 1) return false;
    if(n ==2 || n == 3) return true;
    if(!n%2 || !n%3) return false;
    for(int i = 5 ; i * i <= n ; i++)
        if(!(n%i) || !(n% (i+2))) return false;
    return true;
}

// Sieve of Eratosthenes
bool isPrime_v5(int n){
    if(n == 1) return false;
    int d[n+1] = {0}; 
    for(int i = 2 ; i<= n ;i++){
        if(d[i] == 0){
            d[i] = 2;
            for(int j = i+i ; j<= n;j+=i){
                d[j] = 1;
            }
        }
    }
    // vector<int> primes;
    // for(int i = 0 ; i < n+1 ;i ++){
    //     if(d[i]==2) {primes.push_back(i);}
    // }
    return (d[n]==2) ? true : false;
}

// Refactored - better code : Sieve of Eratosthenes
bool isPrime_v6(int n){
    if(n == 1) return false;
    vector<bool> d (n+1,true); 
    d[0] = d[1] = false;
    for(int i = 2 ;i*i<= n ;i++){
        if(d[i]){
            for(int j = i*i ; j<= n;j+=i){
                d[j] = false;
            }
        }
    }
    // vector<int> primes;
    // for(int i = 0 ; i < n+1 ;i ++){
    //     if(d[i]) {primes.push_back(i);}
    // }
    return d[n];
}

int main()
{
    int  T,n;
    cin >> T;
    while(T--){
        cin >> n;
        // cout << isPrime_v1(n) << endl;
        // cout << isPrime_v2(n) << endl;
        // cout << isPrime_v3(n) << endl;
        // cout << isPrime_v4(n) << endl;
        // cout << isPrime_v5(n) << endl;
        cout << isPrime_v6(n) << endl;
    }

    return 0;
}