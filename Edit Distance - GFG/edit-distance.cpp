//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int solve(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(i==s.size()){
            return t.size()-j;
        }
        if(j==t.size()){
            return s.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            return solve(i+1,j+1,s,t,dp);
        }
        
        int ins= 1+ solve(i,j+1,s,t,dp);
        int del= 1+ solve(i+1,j,s,t,dp);
        int rep= 1+solve(i+1,j+1,s,t,dp);
        dp[i][j]= min(ins,min(del,rep));
        return dp[i][j];
    }
    int editDistance(string s, string t) {
        // Code here
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends