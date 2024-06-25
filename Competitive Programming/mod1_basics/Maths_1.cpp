#include "../display.h"

#include <vector>
#include <set>
#include <math.h>

int reverse_int(int n){
    int t = 0;
    while(n){
        t = t*10 + (n%10);
        n /= 10;
    }
    return t;
}

int count_digits(int  n){
    int t, count;
    t = n;
    count = 0;
    while(t > 0){
        t = t/10;
        count++;
    }
    return count;
}

int gcd_1(int n,int m){
    int gcd = 1;
    for(int i = 2 ; i <= min(n,m);i++){
        if(!(n%i) && !(m%i)) 
            gcd = i;
    }
    return gcd;
}

int gcd_2(int n,int m){
    for(int i = min(n,m); i >= 1;i--){
        if(!(n%i) && !(m%i)) 
            return i;
    }
    return 1;
}

int gcd_3(int n,int m){
    if(min(n,m) <= 1) return max(m,n);
    return (n > m)? gcd_3(n - m,m) : gcd_3(m - n,n);
}

int gcd_4(int n,int m){
    if(min(n,m) == 0) return max(m,n);
    return (n > m)? gcd_4(n % m,m) : gcd_4(m % n,n);
}

int armstrong(int n){
    int Y = ceil(log10(n)) , ams = 0 , t = n;
    while(t){
        ams += pow( t%10 , Y);
        t /= 10;
    }
    return ams == n;
}

void print_divisors(int n){
    cout << "Divisors : ";
    set<int> div;
    for(int i = 1 ; i <= sqrt(n) ; i++ ){
        if((n % i) == 0) {
            div.insert(i);
            div.insert(n/i);
        }
    }
    for(auto &m: div) cout << m << " "; cout << endl;
}

bool is_prime_1(int n){
    // O(n)
    for(int i = 2 ; i < n; i++)
        if(n %i == 0) return false;
    return true;
}

bool is_prime_2(int n){
    // O(n)
    for(int i = 2 ; i < n/2; i++)
        if(n %i == 0) return false;
    return true;
}

bool is_prime_3(int n){
    // O( sqrt(n) )
    for(int i = 2 ; i <= sqrt(n); i++)
        if(n %i == 0) return false;
    return true;
}

bool is_prime_4(int n){
    // All primes are of the form 6𝑘±1 except for 2 and 3.
    // O( sqrt(n) )
    if(!(n%2) || !(n%3)) return 0;
    for(int i = 1 ; i <= sqrt(n); i++)
        if(!(n %((6*i)-1))|| !(n % ((6*i)+1))) 
            return false;
    return true;
}

int main()
{
    int n = 360739867;
    // Count Digits 
    cout << "Count Digits " <<endl;
    // Method 1
    int count,t;
    count = count_digits(n);
    cout << "1 : No of digits = " << count << endl;
    // or
    count = 0;
    for(int i = n ; i > 0 ; i /= 10) count++;
    cout << "1 : No of digits = " << count << endl;
    // Method 2
    cout << "2 : No of digits = " << ceil(log10(n)) << endl;
    // cout << "2 : No of bits = " << ceil(log2(n)) << endl;

    // Reverse a Number
    cout << n << " -> Reversed : " << reverse_int(n)<< "\n";

    // Check Palindrome
    int p = 112232211 ;
    (p == reverse_int(p))? cout << "Palindrome\n" : cout << "Not Palindrome\n";
    p = n ;
    (p == reverse_int(p))? cout << "Palindrome\n" : cout << "Not Palindrome\n";

    // GCD Or HCF
    cout << "gcd of 12,48 = "<<  gcd_1(12,48) << endl;
    cout << "gcd of 10,72 = "<<  gcd_1(10,72) << endl;
    cout << "gcd of 97,23 = "<<  gcd_1(97,23) << endl;
    cout << "gcd of 12,48 = "<<  gcd_2(12,48) << endl;
    cout << "gcd of 10,72 = "<<  gcd_2(10,72) << endl;
    cout << "gcd of 97,23 = "<<  gcd_2(97,23) << endl;
    cout << "gcd of 12,48 = "<<  gcd_3(12,48) << endl;
    cout << "gcd of 10,72 = "<<  gcd_3(10,72) << endl;
    cout << "gcd of 97,23 = "<<  gcd_3(97,23) << endl;
    cout << "gcd of 12,48 = "<<  gcd_4(12,48) << endl;
    cout << "gcd of 10,72 = "<<  gcd_4(10,72) << endl;
    cout << "gcd of 97,23 = "<<  gcd_4(97,23) << endl;


    // Armstrong Numbers
    (armstrong(371))? cout << "armstrong\n" :  cout << "Not armstrong\n" ;
    (armstrong(1634))? cout << "armstrong\n" :  cout << "Not armstrong\n" ;
    (armstrong(123))? cout << "armstrong\n" :  cout << "Not armstrong\n" ;

    // Print all Divisors
    print_divisors(48);
    print_divisors(144);
    print_divisors(97);

    // Check for Prime
    is_prime_1(97) ? cout << "Prime\n": cout << "Not Prime\n" ;
    is_prime_1(1299) ? cout << "Prime\n": cout << "Not Prime\n" ;
    is_prime_2(97) ? cout << "Prime\n": cout << "Not Prime\n" ;
    is_prime_2(1299) ? cout << "Prime\n": cout << "Not Prime\n" ;
    is_prime_3(97) ? cout << "Prime\n": cout << "Not Prime\n" ;
    is_prime_3(1299) ? cout << "Prime\n": cout << "Not Prime\n" ;
    is_prime_4(97) ? cout << "Prime\n": cout << "Not Prime\n" ;
    is_prime_4(1299) ? cout << "Prime\n": cout << "Not Prime\n" ;

    return 0;
}