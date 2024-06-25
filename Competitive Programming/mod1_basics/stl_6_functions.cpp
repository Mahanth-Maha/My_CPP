#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

template<class T> 
void dis(const vector<T> &v){
    for(auto &it: v ){
        cout << it << " ";
    }
    cout << "\n";
}
template<class T> 
void dis2(const pair<T, T> v[], int n){
    for(int it = 0 ; it < n ;it++ ){
        cout << v[it].first << ":" << v[it].second << ";\t";
    }
    cout << "\n";
}

bool comp(const pair<int, int> p1, const pair<int, int> p2){
    if(p1.second == p2.second)
            return p1.first < p2.first;
    return p1.second > p2.second;
}


int main(){

    // SORT

    vector<int> v = {1,6,3,6,2632,623,6243,56,236,2345,623,3456,435,47};
    dis(v);
    sort(v.begin(),v.end());
    dis(v);
    sort(v.begin(),v.end(),greater<int>());
    dis(v);

    pair<int, int> a[] = {{1,8},{5,3},{6,4},{7,5},{8,5},{3,6},{2,5},{9,8},{4,5},{9,2}};
    dis2(a,10);
    sort(a,a+10);
    dis2(a,10);
    pair<int,int> b[] = {{1,8},{5,3},{6,4},{7,5},{8,5},{3,6},{2,5},{9,8},{4,5},{9,2}};
    dis2(b,10);
    // own sorting : Acc to 2 nd , if same sort acc to 1 st
    sort(b,b+10,comp);
    dis2(b,10);

    // count bits
    cout <<"\nset bits in 7 = " << __builtin_popcount(7);
    cout << "\nset bits in 14235 = " << __builtin_popcount(14235);
    cout << "\nset bits in (long long) 1423543562362 = " << __builtin_popcountll(1423543562362);
    cout << "\n";
    //NEXT PERMUTATIONS
    string s = "abc";
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));
    vector<int> v2 = {1,2,3};
    cout << "\nShould Start sorted for all permutations\n";
    cout << "vector :" ;
    for(auto &i : v2) cout << i<< " ";
    cout << "\npermutations :\n";
    do{
        for(auto &i : v2) cout << i << " "; cout << endl;
    }while(next_permutation(v2.begin(),v2.end()));
    vector<int> v3 = {2,3,1};
    
    cout << "\nvector :" ;
    for(auto &i : v3) cout << i<< " ";
    cout << "\npermutations :\n";
    do{
        for(auto &i : v3) cout << i << " "; cout << endl;
    }while(next_permutation(v3.begin(),v3.end()));

    // max element
    vector<int> v4 = {1,6,3,6,2632,623,6243,56,236,2345,623,3456,435,47};
    cout << "Vec : ";
    dis(v4);
    cout << "Max element in vec = " << *max_element(v4.begin(),v4.end());
    
    // lower bound - always returns a iterator 
    // if exists first occurrence
    // if not exits pointer to next element
    cout << "\nlower & upper bounds\n";
    vector<int >vec = {1,2,3,3,4,5,6,6,9,9,9};
    dis(vec);
    auto vit2 = lower_bound(vec.begin(), vec.end(), 3);
    (*vit2 == 3)? cout << "3 found" :cout << "3 not found" ;
    cout << "\n3 lb points to : " << *vit2 << " index : "<< vit2 - vec.begin() << endl;
    auto vit = lower_bound(vec.begin(), vec.end(), 7);
    (*vit == 7)? cout << "7 found" :cout << "7 not found" ;
    cout << "\n7 lb points to : " << *vit << " index : "<< vit - vec.begin() << endl;
    auto vit3 = lower_bound(vec.begin(), vec.end(), 12);
    (vit3 != vec.end() || *vit3 == 12)? cout << "12 found" :cout << "12 not found" ;
    cout << "\n12 lb points to : " << *vit3 << " index : "<< vit3 - vec.begin() << endl;


    cout << "\nUpper bound\n";
    dis(vec);
    auto vitt1 = upper_bound(vec.begin(), vec.end(), 6);
    (vitt1 != vec.end() || *vitt1 == 6)? cout << "6 found" :cout << "6 not found" ;
    cout << "\n6 ub points to : " << *(vitt1-1 )<< " index : "<< vitt1 - 1 - vec.begin() << endl;
    auto vitt2 = upper_bound(vec.begin(), vec.end(), 3);
    (vitt2 != vec.end() || *vitt2 == 3)? cout << "3 found" :cout << "3 not found" ;
    cout << "\n3 ub points to : " << *(vitt2-1 )<< " index : "<< vitt2 - 1 - vec.begin() << endl;
    auto vitt3 = upper_bound(vec.begin(), vec.end(), 12);
    (vitt3 != vec.end() || *vitt3 == 12)? cout << "12 found" :cout << "12 not found" ;
    cout << "\n12 ub points to : " << *(vitt3-1 )<< " index : "<< vitt3 - 1 - vec.begin() << endl;


    vector<tuple<int,int,int>> vt ;
    vt.push_back({1,2,3});
    vt.push_back({3,4,2});
    vt.push_back({5,3,2});
    vt.push_back({1,2,5});
    vt.push_back({3,4,3});
    vt.push_back({5,4,2});
    cout << "\n3 - Tuple Vector" << endl;
    for(auto &it : vt )
        cout << "(" << get<0>(it) << " ," << get<1>(it) << " ," << get<2>(it) << " )"<< endl;
    sort(vt.begin(),vt.end());
    cout << "\n3 - Tuple Vector SORTED" << endl;
    for(auto &it : vt )
        cout << "(" << get<0>(it) << " ," << get<1>(it) << " ," << get<2>(it) << " )"<< endl;



    return 0;
}