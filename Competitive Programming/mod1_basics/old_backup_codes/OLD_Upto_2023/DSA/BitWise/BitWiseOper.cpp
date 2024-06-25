#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

int main()
{
    unsigned int  T,n,m;
    cin >> T;
    while(T--){
        cin >> n >>m;
        LOG((n & m));
        LOG((n | m));
        LOG((~m));
        LOG((n >> m));
        LOG((n << m));
        LOG((n ^ m));
    }

    return 0;
}