#include "display.h"

#include <vector>
#include <map>
#include <algorithm>


int main()
{
    vector<int> v = {1,2,3,3,3,1,1,2,3,2,4};
    display(v.begin(), v.end());
    cout << "shuffle : " ;
    random_shuffle(v.begin(),v.end());
    display(v.begin(), v.end());
    cout << "sorted : " ;
    sort(v.begin(),v.end());
    display(v.begin(), v.end());
    cout << "reverse : " ;
    reverse(v.begin(),v.end());
    display(v.begin(), v.end());

    map<int, int> m = {{1,4},{5,4},{5,5},{7,7},{2,3},{5,2},{-1,5}};
    display_pair(m.begin(), m.end());
    display_pair(m.begin(), m.end());

    return 0;
}