#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define LOG(x) std::cout << x << std::endl;

using namespace std;

vector<string> PowerSetOfString(string s){
    int n = s.size(), num = 1<<n;
    vector<string> vs;
    for(int i = 0 ; i< num ; i++){
        string temp = "";
        for(int k = 0 ; k < n ; k++){
            if((i & (1<<k))) temp.push_back(s[k]);
        }
        vs.push_back(temp);
    }
    return vs;
}

int main()
{
    int  T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        vector<string> vs = PowerSetOfString(s);
        sort(vs.begin(),vs.end());
        for(auto &i: vs) cout << i << endl;
    }

    return 0;
}