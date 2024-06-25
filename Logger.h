#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

#include <algorithm>

#include <string>
#include <cmath>

using namespace std;

template <typename T>
void log_vec(vector<T>& v){
    cout << "Values : "  ;
    for(auto &i: v) cout << i << " ";
    cout << endl;
}

template< class RandomIt >
void log_any( RandomIt first, RandomIt last ){
    cout << "Values : ";
    for(auto i = first ; i != last; i++ ) cout << *i << " ";
    cout << endl;
}

template< class RandomIt >
void log_any_pair( RandomIt first, RandomIt last ){
    cout << "Key : Value\n";
    for(auto i = first ; i != last; i++ ) cout << i->first << "\t:" << i->second << "\n";
}

#endif 