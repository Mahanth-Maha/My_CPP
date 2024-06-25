#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

bool kthBitSet(int n,int k){
    return (n & (1<<(k-1)));
}

int main()
{
    int  T,n;
    cin >> T;
    while(T--){
        int k;
        cin >> n >> k;
        cout << kthBitSet(n,k) << endl;
    }

    return 0;
}