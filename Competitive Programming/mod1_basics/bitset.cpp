#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


#include <bitset>

using namespace std;

int main()
{
    bitset<10> b;
    b[1] = true;
    b[5] = 1;
    for(int i = 0; i < b.size(); i++) cout << b[i] << " ";
    string s = "1111000011110000";
    bitset<16> a(s);  // RIGHT to LEFT
    for(int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
    
    cout << "No of set bits : " << a.count() << endl;
    string s2 = a.to_string();
    cout << "length of int in bits : " << lower_bound(s2.begin(), s2.end(), '1') - s2.begin()  << endl;

    bitset<8> A(string("11001100")), B(string("10101010")) ;
    cout << "A     :"<< A << endl; 
    cout << "B     :"<< B << endl; 
    cout << "---------------\n";
    cout << "A | B :" << (A | B) << endl;
    cout << "A & B :" << (A & B)<< endl;
    cout << "A ^ B :" << (A ^ B)<< endl;
    cout << "\nset 4 th bit \n";
    bitset<16> C;
    cout << C << endl;
    C.set(3,1);
    cout << C << endl;
    cout << "\nflip 5th bit \n";
    C.flip(4);
    cout << C << endl;
    
    cout << "\nflip all bits \n";
    C.flip(); 
    cout << "\nTest 3 rd bit \n";
    cout << C.test(2); 
    cout << "\nTest 4 th bit \n";
    cout << C.test(3); 

    cout << "\nreset all bits \n";
    C.reset();
    cout << C << endl;
    cout << "\nset all bits \n";
    C.set();
    cout << C << endl;
    

    return 0;
}