#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool is_in(vector<int>& a, int k){
    for(int j = 0; j < a.size(); j++)
        if(a[j] == k) return 1 ;
    return 0;
}

int main()
{
    int n,m;
    cin >> n ;
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int i = 0 ; i < m ;i++) cin >> b[i];
    vector<int> intersection_ab ;
    vector<int> union_ab ;

    //Brute 
    /*
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(a[i] == b[j] && !is_in(intersection_ab,a[i]) ) {  
                intersection_ab.emplace_back(a[i]);
            }
        }
    }
    union_ab = a;
    for(int i = 0 ;i < m;i++){
        if(!is_in(union_ab,b[i])) union_ab.emplace_back(b[i]);
    }
    sort(intersection_ab.begin(), intersection_ab.end());
    sort(union_ab.begin(), union_ab.end());
    */


    //Better O(n + d) == O(n) with O(d) space 
    /*
    set<int> a1,b1;
    for(int i = 0 ; i < n ; i ++) a1.insert(a[i]);
    for(int i = 0 ; i < m ; i ++) b1.insert(b[i]);
    for(auto &i : a1){
        if(b1.find(i) != b1.end()){
            intersection_ab.emplace_back(i);
        }
    }
    for(auto &j: b1 )
        a1.insert(j);
    for(auto &i:a1)
        union_ab.emplace_back(i);
    */


    //  OPTIMAL 
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            intersection_ab.emplace_back(a[i]);
            union_ab.emplace_back(a[i]);
            i++;
            j++;
        }
        else if(a[i] > b[j]){
            union_ab.emplace_back(b[j]);
            j++;
        } else {
            union_ab.emplace_back(a[i]);
            i++;
        }
    }

    while(i < n)
        union_ab.emplace_back(a[i++]);
    while(j < m)
        union_ab.emplace_back(b[j++]);

    for(int i = 0 ; i < intersection_ab.size() ;i++) cout << intersection_ab[i] << " ";cout <<endl;
    for(int i = 0 ; i < union_ab.size() ;i++) cout << union_ab[i] << " ";

    return 0; 
}

/*
Input :(n,d,arr)
9
2 5 7 3 4 8 6 1 22
6
1 12 4 3 10 11
Output :
1 3 4
1 2 3 4 5 6 7 8 10 11 12 22
*/