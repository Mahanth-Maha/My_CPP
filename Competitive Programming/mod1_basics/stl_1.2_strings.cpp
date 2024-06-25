#include <iostream>
#include <algorithm>
#include <bitset>
// #include <string>


using namespace std;

int main(){
    string a = "hello", b = "HELLO";
    cout << a << b << endl;
    cout << a + b << endl;
    string c = a  + " " + b;
    cout << c << endl;

    string s = "The string structure is also a dynamic array that can be used almost like a vector. In addition, there is special syntax for strings that is not available in other data structures. Strings can be combined using the + symbol. The function substr(k,x) returns the substring that begins at position k and has length x, and the function find(t) finds the position of the first occurrence of a substring t\n";
    cout << "s = " << s;
    cout << s.substr(4,6) << endl; // [Start , length)
    int k = s.find("substr");
    cout << "first occurrence of 'substr' @ " << k  << endl; 
    s[k] = 'S';
    s[k + 3 ] = 'S';
    cout << "s = " << s;
    int n = 14;
    cout << "\nn : " << n ; 
    cout << "\n32 bit binary representation : " << bitset<32>(n).to_string();
    cout << "\nNo of set bits: " << bitset<32>(n).count();
    string nstr = bitset<32>(n).to_string();
    auto itt = lower_bound( nstr.begin(), nstr.end() , '1');
    cout << "\nSize of n in binary: " << nstr.size() - (itt - nstr.begin());
    
    

    return 0;
}