#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &v){
    for(int i = 0 ;i < v.size();i ++){
        int swapped = 0;
        for(int j = i ; j< v.size();j++){
            if(v[i] > v[j]){
                swapped = 1;
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        if(swapped == 0) return;
    }
}
void selection_sort(vector<int> &v){
    for(int i = 0 ;i < v.size();i ++){
        int minimum = i;
        for(int j = i+1 ; j< v.size();j++){
            if(v[minimum] > v[j])
                minimum = j;
        }
        if( i != minimum){
            int temp = v[i];
            v[i] = v[minimum];
            v[minimum] = temp;   
        }
    }
}
void insertion_sort(vector<int> &v){
    for(int i  = 1 ; i< v.size(); i++){
        int k = v[i], j = i - 1;
        while(j >= 0 &&  v[j] > k ){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = k ;
    }
}

void merge(int p, int q, int r, vector<int> &v,vector<int> &a){
    int i = p,  j =  q + 1, k = p;
    while(i <= q && j <= r){
        a[k++] = (v[i] < v[j]) ? v[i++] : v[j++];
    }
    while(i <= q){
        a[k++] = v[i++];
    }
    while(j <= r){
        a[k++] = v[j++];
    }
    for(i = p ; i <=r ; i++){
        v[i] = a[i];
    }
}
void merge_s(int i , int j , vector<int> &v,vector<int> &a){
    if(i == j) return;
    if(i+1 == j){
        if(v[i] > v[j]) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
        return;
    }
    if( i < j){
        int mid = (i + j) /2;
        merge_s(i,mid,v,a);
        merge_s(mid+1,j,v,a);
        merge(i,mid,j,v,a);
    }
}
void merge_sort(vector<int> &v){
    vector<int> a(v.size());
    merge_s(0,v.size()-1,v,a);
}

int partition(int p,int q, vector<int>& v){
    int pivot = q;
    int i = p-1 , j = p;

    while(j != q){
        if(v[j] < v[pivot]){
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
        j++;
    }
    i++;
    int temp = v[pivot];
    v[pivot] = v[i];
    v[i] = temp;

    return i;
}
void quick_s(int p , int q , vector<int> &v){
    if( p < q){
        int pivot = partition(p,q,v);
        quick_s(p,pivot - 1,v);
        quick_s(pivot + 1,q,v);
    }
}
void quick_sort(vector<int> &v){
    quick_s(0,v.size()-1,v);
}

int main(){
    int n;
    cin >> n; // for 10000 ints
    vector<int> v(n);
    for(int i=0; i< n;i++)
        cin >> v[i];
        
    // bubble_sort(v); // 721 ms 
    // selection_sort(v); // 335 ms 
    // insertion_sort(v); // 192 ms 
    
    // merge_sort(v); // 44 ms 
    // quick_sort(v); // 48 ms

    sort(v.begin(),v.end()); // 45 ms
    // to sort reverse
    // sort(v.begin(),v.end(), greater<int>); // 45 ms

    for( auto &i : v)
        cout << i << " ";

    return 0;
}


/*
inputs

Test Case 1 :
60
31 69 13 61 51 25 2 61 60 19 22 79 59 63 45 73 90 43 7 94 7 48 98 82 100 54 2 55 48 40 57 60 48 34 70 80 77 69 4 33 18 63 25 34 70 38 50 82 58 6 26 79 93 26 47 31 56 16 6 81
Expected Output : 
2 2 4 6 6 7 7 13 16 18 19 22 25 25 26 26 31 31 33 34 34 38 40 43 45 47 48 48 48 50 51 54 55 56 57 58 59 60 60 61 61 63 63 69 69 70 70 73 77 79 79 80 81 82 82 90 93 94 98 100

Test Case 2 :
10
14 93 43 32 61 62 77 80 8 38
Expected Output : 
8 14 32 38 43 61 62 77 80 93

*/