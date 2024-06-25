//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int N,int arr[],int i,int s,int cs){
        if(s - cs == cs) return 1;
        if(!(i < N)) return 0;
        return solve(N,arr,i+1,s,cs + arr[i]) | solve(N,arr,i+1,s,cs); 
    }
    int equalPartition(int N, int arr[])
    {
        int s =0;
        for(int i = 0 ;i < N ; i++) s+= arr[i];
        if(s%2) return false;
        vector<vector<bool>> dp (N+1, vector<bool> (s+1 , false));
        // vector<vector<int>> su (N+1, vector<int> (s+1 , false));
        // return solve(N,arr,0,s,0);
        int target = s/2;
        for(int j = 1; j< target+1;j++){
            for(int i = 1; i< N+1;i ++){
                if(j == arr[i-1]) dp[i][j] = true;
                else if(dp[i-1][j]) dp[i][j] = true;
                else if((j - arr[i-1]) >= 0 ){
                    if( dp[i-1][ j - arr[i-1] ])
                        dp[i][j] = true;
                }
            }
        }
        for(int i = 1; i< N+1;i ++){
            for(int j = 1; j< target+1;j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return dp[N][target];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends