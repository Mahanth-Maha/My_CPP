#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;
template<class T> 
void dv(const set<T> &v){
    for(auto &it: v ){
        cout << it << " ";
    }
    cout << "\n";
}

int main(){
    set<int> s; // Stores in ordered set
    unordered_set<int> us; // Stores in UNordered set 
    multiset<int> ms; // Stores in ordered MULTI set
    unordered_multiset<int> ums; // Stores in UNordered MULTI set

    s.insert(84);
    s.insert(60);
    s.emplace(50);
    s.emplace(40);
    s.emplace(50);
    s.emplace(40);
    s.emplace(40);

    for(auto &it : s) cout << it << " "; cout << endl;
    // find
    auto f = s.find(10);
    if(f == s.end()) cout << "10 NOT FOUND" << endl;
    auto ff = s.find(40);
    cout << *ff << endl;
    
    cout << " >> erase 50" << endl;
    s.erase(50);
    for(auto &it : s) cout << it << " "; cout << endl;
    cout << "finding 50 " << endl;
    (s.find(50) ==s.end())?cout << "Not found" :cout << "found" ;

    s.erase(s.find(84));
    cout << "finding 84 and then erasing " << endl;
    for(auto &it : s) cout << it << " "; cout << endl;

    // unordered_set  : "NO" upper bound and lower bound functions 

    return 0;
}