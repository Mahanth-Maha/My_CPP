#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;


//linear implementation
string::iterator lbound(string::iterator begin ,string::iterator end, char key ){
    string::iterator it = begin;
    while(it != end){
        if(*it == key) return it;
        it++;
    }
    return it;
}

//binary implementation
string::iterator lbound_bin(string::iterator begin ,string::iterator end, char key ){
    auto  mid = begin + (end - begin)/2 ;
    if(begin == end ) return begin;
    if(*mid < key)
        return lbound_bin(mid + 1, end , key);
    // else if(*mid >= key)   // Equal -> go lower 
    return lbound_bin(begin, mid , key); // mid instead of mid - 1 -> might be itself 
}

// clean implementation of LB
string::iterator lbound_binSearch(string::iterator begin ,string::iterator end, char key ){
    if(begin == end ) return begin;
    auto  mid = begin + (end - begin)/2 ;
    return (*mid < key) ? lbound_bin(mid + 1, end , key) : lbound_bin(begin, mid , key);
}

// clean Vector implementation of LB
vector<int>::iterator lbound_binSearch_vec(vector<int>::iterator begin ,vector<int>::iterator end, int key ){
    if(begin == end ) return begin;
    auto  mid = begin + (end - begin)/2 ;
    return (*mid < key) ? lbound_binSearch_vec(mid + 1, end , key) : lbound_binSearch_vec(begin, mid , key);
}

int main(){

    string s = "0000000000000000011111111111111111111";
    cout << "String : " << s << "\nlen : " << s.size();
    // char k = '0';
    char k = '1';
    auto it = lower_bound(s.begin(), s.end(), k);
    // auto myit = lbound(s.begin(), s.end(), k);
    // auto myit = lbound_bin(s.begin(), s.end(), k);
    auto myit = lbound_binSearch(s.begin(), s.end(), k);
    ( it == myit)? cout << "\n[+] Correct Implementation"  << endl : cout << "\n[-] Wrong Implementation"  << endl ;

    vector<int> vec = { 0,0,0,0,1,1,2,2,3,3,2,2,3,1,1,1,1,2,3,3,4,3,3,2,3,2,3,2,3,2,4,3,2,3,3,3,2,2,2,3,2,2,4};
    sort(vec.begin(),vec.end());
    cout << "\nVector : ";
    for(auto &i : vec) cout << i << " "; cout << "\nSize : " << vec.size();
    int key = -1;
    auto itv = lower_bound(vec.begin(), vec.end(), key);
    auto myitv = lbound_binSearch_vec(vec.begin(), vec.end(), key);
    ( itv == myitv)? cout << "\n[+] Correct Implementation"  << endl : cout << "\n[-] Wrong Implementation"  << endl ;

    return 0;
}