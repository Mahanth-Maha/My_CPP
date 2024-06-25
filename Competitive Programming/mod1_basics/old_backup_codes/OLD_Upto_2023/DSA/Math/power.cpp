#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

long long power1(int a,int b){
    long long temp = 1;
    for(int i = 0 ; i < b ; i ++){
        temp *= a;
    }
    return temp;
}
long long power2(int a,int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    if(!(b%2)){
        long long temp = power2(a,b/2);
        return temp * temp;
    } 
    return power2(a,b-1)*a;
}

long long power3(int a,int b){
    if(b == 0) return 1;
    long long temp = power3(a,b/2);
    temp *= temp;
    return (b%2)? temp*a : temp;
}

int main()
{
    int  T,n;
    cin >> T;
    while(T--){
        int a,b;
        cin >> a >> b;
        // cout << power1(a,b) << endl;
        // cout << power2(a,b) << endl;
        cout << power3(a,b) << endl;
    }

    return 0;
}