#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

#include "Logger.h"

using namespace std;

int main()
{
    int  T,n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << n << endl;
    }
    int N = 9;

    // V
    vector<int> v;
    for(int i = 0 ; i < N;i++)v.push_back(i);
    log_any(v.begin(),v.end());
    
    // S
    stack<int> st;
    for(int i = 0 ; i < N;i++)st.push(i);
    // log_any(st.begin(),st.end());
    
    // Q
    queue<int> q;
    for(int i = 0 ; i < N;i++)q.push(i);
    // log_any(q.begin(),q.end());
    
    //PQ
    priority_queue<int> pq;
    for(int i = 0 ; i < N;i++)pq.push(i);
    // log_any(pq.begin(),pq.end());
    // /*
    unordered_set<int> s;
    set<int> os;
    unordered_map<int,int> m;
    map<int,int> om;
    for(int i = 0 ; i < N;i++)s.insert(i);
    log_any(s.begin(),s.end());
    for(int i = 0 ; i < N;i++)os.insert(i);
    log_any(os.begin(),os.end());
    for(int i = 0 ; i < N;i++)m[i] = i;
    log_any_pair(m.begin(),m.end());
    for(int i = 0 ; i < N;i++)om[i] = i;
    log_any_pair(om.begin(),om.end());
    // */
    return 0;
}

