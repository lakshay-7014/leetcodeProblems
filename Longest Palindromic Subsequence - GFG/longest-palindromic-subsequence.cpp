//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(string &a , string &b , int i , int j , vector<vector<int>> &dp,int n ){
        if(i>=n || j>=n){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(a[i]==b[j]){
            return 1+ solve(a,b,i+1,j+1,dp,n);
        }
        int ans= max(solve(a,b,i+1,j,dp,n),solve(a,b,i,j+1,dp,n));
        return dp[i][j]=ans;
        
    }
    int longestPalinSubseq(string a) {
        //code here
        int n = a.size();
        string b = a;
        reverse(b.begin(),b.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(a,b,0,0,dp,n);
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends