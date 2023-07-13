#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;


void printDiv(int n,int i){
    if(i*i <= n && !(n%i)){
        cout << i << " ";
        printDiv(n,i+1);
        if(i != n/i) 
            cout << n/i << " ";
    }
}

int main()
{
    int  T;
    cin >> T;
    while(T--){
        int n;
        cin >>n;
        printDiv(n,1) ;
    }

    return 0;
}