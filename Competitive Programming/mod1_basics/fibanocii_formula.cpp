#include "iostream"
#include "math.h"

double fib(double n){
    return (pow(1 + sqrt(5),n ) - pow(1 - sqrt(5) ,n ) )/(double) (pow(2,n)*sqrt(5));
}

int fib_rec(int n){
    if(n == 0 || n == 1) return n;
    return fib_rec(n - 1) + fib_rec( n-2);
}

int main(){
    int a1 = 0,a2 = 1;
    std::cout << "Iterative:: \t";

    // GENERAL

    std::cout << 0 << ":" << a1 << "\t";
    std::cout << 1 << ":" << a2 << "\t";
    for(int i=2;i<=10 ;i++){
        int temp  = a2;
        a2 = a1 + a2;
        a1 = temp;
        std::cout << i << ":" << a2 <<  "\t";
    }
    std::cout << "\nRecursive:: \t";

    // RECURSIVE

    for(int i=0;i<=10 ;i++){
        std::cout << i << ":" << fib_rec(i) <<  "\t";
    }
    std::cout << "\nFormula  :: \t";

    // FORMULA :: Binet’s formula

    for(int i=0;i<=10 ;i++){
        std::cout << i << ":" << fib(i) <<  "\t";
    }


    return 0;
}