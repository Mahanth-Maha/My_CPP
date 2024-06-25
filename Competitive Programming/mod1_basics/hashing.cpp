#include "../display.h"

#include <unordered_map>

int main()
{
    unordered_map<int,int> m ;
    vector<int> arr = {1,2,1,2,2,2,2,3,4,4,5,5,3,2,5,6,6,7,3,3,3,5,6,3,6,3,6,5,2,3,6,5,6,2,5,3,6,5,3,6,2,4,3,6};

    for(auto &i : arr) {
        if(m.find(i) == m.end()) m[i] = 0;
        m[i]++;
    }
    
    pair<int,int> maxpair ={0,INT_MIN} , minpair = {0,INT_MAX};
    for(auto &i: m){
        if(maxpair.second < i.second)
            maxpair = i;
        else if(minpair.second > i.second)
            minpair = i;
    }

    cout << "max frequency :" << maxpair.first  << " of frequency = " << maxpair.second <<endl ;
    cout << "min frequency :" << minpair.first << " of frequency = " << minpair.second <<endl ;

    return 0;
}