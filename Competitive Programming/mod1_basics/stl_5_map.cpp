#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){

    map<int,int> m = {{1,80},{5,37},{6,40},{7,54},{8,56},{3,69},{2,50},{9,98}}; 
    for(auto &it : m) cout << it.first << ":" << it.second << endl;
    m[1] = 10;
    cout << "Modified\n";
    for(auto &it : m) cout << it.first << ":" << it.second << endl;
    m.emplace(13,43);
    m.insert({12,35});
    cout << "Modified 2 : \n";
    for(auto &it : m) cout << it.first << ":" << it.second << endl;
    cout << "size : " << m.size();

    m.erase(12);
    cout << "\nErase 12 \tsize : " << m.size() << endl;
    cout << "\n\nMULTI MAP\n\n";
    multimap<int,int> mm = {{1,80},{5,37},{6,40},{7,54},{8,56},{3,69},{2,50},{9,98},{1,86},{5,47},{6,96},{7,44}}; 
    for(auto &it : mm) cout << it.first << ":" << it.second << endl;
    if(mm.end() == mm.find(55)) cout << "55 Not found\n" ;
    for(auto &it : mm) cout << it.first << ":" << it.second << endl;
    if(mm.end() == mm.find(5)) cout << "5 not found\n";
    mm.erase (mm.lower_bound(5));
    cout << "Erased first occurrance of key 5 \n";
    for(auto &it : mm) cout << it.first << ":" << it.second << endl;
    mm.erase (mm.upper_bound(7));
    cout << "Erased last occurrance of key 7 \n";
    for(auto &it : mm) cout << it.first << ":" << it.second << endl;
    return 0;
}