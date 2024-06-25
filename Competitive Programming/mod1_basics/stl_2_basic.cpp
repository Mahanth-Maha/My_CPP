#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;
template<class T> 
void dv(const vector<T> &v){
    for(auto &it: v ){
        cout << it << " ";
    }
    cout << "\n";
}
template<class T> 
void dl(const list<T> &v){
    for(auto &it: v ){
        cout << it << " ";
    }
    cout << "\n";
}
template<class T> 
void dd(const deque<T> &v){
    for(auto &it: v ){
        cout << it << " ";
    }
    cout << "\n";
}

int main(){

    list<int> l = {1,4,6,2,5};
    dl(l);

    l.push_front(-100);
    dl(l);
    l.emplace_front(-200);
    dl(l);
    //all other operations same as vector

    // DEQUEUE === LIST
    deque<int> dq = {1,4,6,2,5};
    dd(dq);

    dq.push_front(-100);
    dd(dq);
    dq.emplace_front(-200);
    dd(dq);

    // use deque is preferred when RANDOM ACCESS is required 
    
    // list is implemented with "doubly linked list" so more freedom & memory

    return 0;
}