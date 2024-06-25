//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    vector<vector<int>> dp (n+2, vector<int>(n+2,0));
		    for(int i = 0 ;i < n;i++){
		        for(int j= i+1 ;j < n;j++){
    		        dp[i+1][j+1] = (str[i] == str[j]) ?  1 + dp[i][j] : ((dp[i+1][j] > dp[i][j+1] )?dp[i+1][j]:dp[i][j+1]);
    		        // dp[i+1][j+1] = (str[i] == str[j]) ?  (1 + dp[i][j]) : max(dp[i+1][j],dp[i][j+1]) ;
		        }
		    }
		    // for(int i = 0 ;i < n+1;i++){
		    //     for(int j = 0 ;j < n+1;j++){
		    //         cout << dp[i][j] << " ";
		    //     }
		    //     cout << "\n";
		    // }
		    return dp[n-1][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends