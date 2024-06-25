//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void log_dp(int dp[51][51],int n,int m){
        for(int i = 0 ; i<= n;i++){
            for(int j = 0 ; j<= m;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
	public:
	    int maxk(int p,int l){
	        return (p>l)?p:l;
	    }
	    
        void backTrack(int dp[51][51],int lcs, set<string>& r,string& s,string& t,string curr, int i,int j){
            if(i > 0 && j > 0){
                if(s[i-1]==t[j-1]){
                    curr.insert (0, 1, s[i-1]);
                    if(curr.size()==lcs){
                        // cout << "inserted : " << curr << endl;
                        r.insert(curr);
                    } else {
                        backTrack(dp,lcs,r,s,t,curr,i-1,j-1);
                    }
                } else {
                    int maxp = maxk(dp[i-1][j],dp[i][j-1]);
                    if(maxp == dp[i-1][j])
                        backTrack(dp,lcs,r,s,t,curr,i-1,j);
                    if(maxp == dp[i][j-1])
                        backTrack(dp,lcs,r,s,t,curr,i,j-1);
                }
            }
        }

		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    int dp[51][51];
            vector<string> res;
            set<string> r;
		    int n = s.size(), m = t.size();
		    for(int i = 0 ; i<= n;i++){ 
		        dp[i][0] = 0;
		    }
		    for(int i = 0 ; i<= m;i++){ 
		        dp[0][i] = 0;   
		    }
		    for(int i = 0 ; i< n;i++){
		        for(int j = 0 ; j< m;j++){
		            dp[i+1][j+1] = (s[i] == t[j])? 1 + dp[i][j] : maxk(dp[i+1][j],dp[i][j+1]);
		        }
		    }
            // log_dp(dp,n,m);
		    int lcs = dp[n][m];
		    // cout << lcs << " ";
            string temps = "";
            backTrack(dp,lcs,r,s,t,temps,n,m);
            for(auto &i:r){
                res.push_back(i);
            }
            return res;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends