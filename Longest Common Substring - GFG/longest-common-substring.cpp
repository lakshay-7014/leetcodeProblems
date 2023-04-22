//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxi=0;
    int solve(string &s1, string &s2, int x , int y , int i , int j ,vector<vector<int>> &dp){
        if(i>=x || j>=y){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans =  1 + solve(s1,s2,x,y,i+1,j+1,dp);
            maxi=max(maxi,ans);
        }
        
        solve(s1,s2,x,y,i+1,j,dp);
        solve(s1,s2,x,y,i,j+1,dp);
        
        return dp[i][j]=ans;
    }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         solve(s1,s2,n,m,0,0,dp);
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends