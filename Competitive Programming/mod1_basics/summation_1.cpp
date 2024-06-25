#include "iostream" 

#define cube(x) (x*x*x)
#define sq(x) (x*x)

int main(){

    int n;
    std::cout << "Enter n :" ;
    std::cin >> n ;
    int s = 0;
    for(int i = 0 ; i<= n ; i ++){
        s += i;
    }
    std::cout << "Summation i \t:" << s << std::endl;
    std::cout << "Summation i F\t:" << (n*(n+1))/2 << std::endl;
    
    s = 0;
    for(int i = 0 ; i<= n ; i ++){
        s += sq(i);
    }
    std::cout << "Summation i^2 \t:" << s << std::endl;
    std::cout << "Summation i^2 F\t:" << (n*(n+1)*(2*n+1))/6 << std::endl;
    s = 0;
    for(int i = 0 ; i<= n ; i ++){
        s += cube(i);
    }
    std::cout << "Summation i^3 \t:" << s << std::endl;
    std::cout << "Summation i^3 F\t:" << ((n*(n+1))/2)*((n*(n+1))/2) << std::endl;
    return 0;
}