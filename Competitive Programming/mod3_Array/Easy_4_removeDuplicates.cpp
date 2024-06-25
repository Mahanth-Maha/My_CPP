#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// remove duplicates in sorted Array inplace

void remove_dups(vector<int> &v){
    int prev = v[0] , j = 1;
    for(int i = 1; i < v.size(); i++){
        if(prev != v[i]) 
            v[j++] = v[i];
        prev = v[i];
    }
}

int main()
{
    int  n;
    cin >> n;
    // OPTIMAL O(n)
    // /*
    int temp;
    vector<int> v;
    set<int> s;
    for(int i = 0 ; i < n;i++){
        cin >> temp;
        v.emplace_back(temp);
        s.insert(temp);
    }

    remove_dups(v);

    // */
    int j = 0;
    for(auto &i :s){
        if(v[j++] != i){
            cout << 0 ;
            return 0;
        }
    }
    cout << 1;

    return 0;
}

/*
Input:
10
15 34 34 44 44 55 68 68 72 93
Output:
{15 34 44 55 68 72 93}
1
*/