#include "../display.h"

#include <vector>
#include <algorithm>

int sum_n(int n){
    if(n == 0) return 0;
    return n + sum_n(n-1);
}

void print(int n){
    if(n == 0) return ;
    cout << n << " ";
    print(n-1 );
}

void print2(int n){
    if(n == 0) return ;
    print2(n-1 );
    cout << n << " ";
}

int factorial(int n){
    return (n <= 1) ? 1 : n* factorial(n-1);
}

void reverse_arr(vector<int>& arr, int i, int j){
    if(i < j ) {
        swap_vec(arr,i,j);
        reverse_arr(arr,i+1, j-1);
    }
}

bool is_palindrome(string s , int i, int j){
    if(s[i] != s[j]) return false;
    return (i < j)? is_palindrome(s,i+1,j-1) : true ;
}

void fib_helper(int n, int a , int b){
    if(n> 0){
        cout << a << " ";
        fib_helper(n-1 , b , a+b);
    }
}

void fib1(int n){
    fib_helper(n,1,1);
}

#include <math.h>
void fib2(int n){
    if(n > 0) {
        fib2(n-1);
        cout << (double)(( pow(1 + sqrt(5), n)) - ( pow( 1 - sqrt(5), n))) / (double) (pow(2,n) * sqrt(5)) << " ";
    }
}

int main()
{
    int n = 10;
    // Print
    cout << n << " Print : " ;
    print(n) ;
    cout << "\n";
    cout << n << " Print Rev : " ;
    print2(n) ;
    cout << "\n";
    // SUM
    cout << n << " Sum : " << sum_n(n) << "\n";
    n = 5;
    // Factorial
    cout << n << " Factorial : " << factorial(n) << "\n";

    // Reverse an Array
    vector<int> arr  = {4,3,1,2,3,6,7,4,8,9};
    sort(arr.begin(),arr.end());
    display(arr.begin(),arr.end());
    reverse_arr(arr,0,arr.size()-1);
    display(arr.begin(),arr.end());

    // Check if a string is palindrome or not
    string s = "abcscbaabcscba";
    cout << s << " is palindrome ? : " << is_palindrome(s, 0 , s.size() - 1) << "\n";
    s = "elll";
    cout << s << " is palindrome ? : " << is_palindrome(s, 0 , s.size() - 1) << "\n";

    // Fibonacci Number
    n = 13;
    cout << n << " fibonacci : " ;
    fib1(n);
    cout << "\n";

    cout << n << " fibonacci : " ;
    fib2(n);
    cout << "\n";

    return 0;
}