#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

int OddOccurrences1(int *arr,int n){
    unordered_map<int,int> m;
    for(int i = 0; i < n ; i++) 
        m[arr[i]]++;
    for(auto &i: m)
        if(i.second%2)
            return i.first;
    return -1;
}


int OddOccurrences2(int *arr,int n){
    unordered_set<int> s;
    for(int i = 0; i < n ; i++) {
        if(s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
        } else {
            s.erase(arr[i]);
        }
    }
    return *s.begin();
}

int OddOccurrences3(int *arr,int n){
    int a = 0;    
    for(int i = 0; i < n ; i++) 
        a = a ^ arr[i];
    return a;
}



int main()
{
    int  T,n;
    cin >> T;
    while(T--){
        cin >> n;
        int arr[n];
        for(int i = 0; i < n ; i++) cin >> arr[i];
        // cout << OddOccurrences1(arr,n) << endl;
        // cout << OddOccurrences2(arr,n) << endl;
        cout << OddOccurrences3(arr,n) << endl;
    }

    return 0;
}