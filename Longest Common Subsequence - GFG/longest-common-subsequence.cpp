//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(string s1, string s2, int x , int y , int i , int j ,vector<vector<int>> &dp){
        if(i>=x || j>=y){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return 1 + solve(s1,s2,x,y,i+1,j+1,dp);
        }
        
        int ans = max(solve(s1,s2,x,y,i+1,j,dp),solve(s1,s2,x,y,i,j+1,dp));
        
        return dp[i][j]=ans;
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        return solve(s1,s2,x,y,0,0,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends