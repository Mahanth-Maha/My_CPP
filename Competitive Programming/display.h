#ifndef DISPLAY_H
// #define DISPLAY_H
#pragma once 

#include <iostream>
#include <vector>

using namespace std;

template< class RandomIt >
void display( RandomIt first, RandomIt last ){
    cout << "(size =" << last - first  << ") Values : " ;
    for(auto i = first ; i != last; i++ ) cout << *i << " ";
    cout << "\n";
}

template< class RandomIt >
void display_pair( RandomIt first, RandomIt last ){
    cout << "\nKey-Value pairs : \t";
    for(auto i = first ; i != last; i++ ) cout << i->first << ":" << i->second << " ;\t";
    cout << "\n";
}

template <class E>
void swap_vec(vector<E>& arr ,E i, E j){
    auto temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp ;
    return;
}

#endif