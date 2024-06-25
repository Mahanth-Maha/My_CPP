#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;


int gcd(int a,int b){
    return (b == 0)? a : gcd(b,a%b); 
}

int main()
{
    int  T;
    cin >> T;
    while(T--){
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }

    return 0;
}