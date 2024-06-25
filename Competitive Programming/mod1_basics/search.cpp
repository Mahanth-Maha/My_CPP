#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int linear(vector<int>& v, int k){
    for(int i = 0 ;i < v.size() ; i ++)
        if(v[i] == k) return i;
    return -1;
}

int bin(vector<int> &v , int k, int i, int j){
    if( i <= j){
        int mid = (i+j)/2;
        if(v[mid] == k) return mid;
        else if(k < v[mid]) return bin(v, k , i,mid-1);
        else if(k > v[mid]) return bin(v, k ,mid+1, j);
    }
    return -1;
}

int binary(vector<int> &v , int k){
    return bin(v,k,0,v.size());
}


int main(){
    int n , k , res;
    cin >> n >> k;
    vector<int> v(n);
    for(int  i = 0;i < n; i++){
        cin >> v[i];
    }
    // res = linear(v, k);
    // res = binary(v, k); 
    // // // res = binary_search(v.begin(),v.end(),k);     
    // // // function in <algorithm> Only gives BOOL
    auto it = lower_bound(v.begin(), v.end(),k);
    res = it - v.begin() ;
    // auto it = upper_bound(v.begin(), v.end(),k);
    // res  = it - v.begin() - 1;
    
    cout << res;
    return 0;
}

/*
inputs

Test Case 1 :
60 55
2 2 4 6 6 7 7 13 16 18 19 22 25 25 26 26 31 31 33 34 34 38 40 43 45 47 48 48 48 50 51 54 55 56 57 58 59 60 60 61 61 63 63 69 69 70 70 73 77 79 79 80 81 82 82 90 93 94 98 100
Expected Output : 32

Test Case 2 :
10 77
8 14 32 38 43 61 62 77 80 93
Expected Output : 7

*/