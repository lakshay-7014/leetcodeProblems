//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int curr, int prev , int n , int a[], vector<vector<int>> &dp){
        if(curr>=n){
            return 0;
        }
        
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        
        int inc=0;
        
        if(prev==-1 || a[curr]>a[prev]){
            inc=1+ solve(curr+1,curr,n,a,dp);
        }
        int exc= 0+ solve(curr+1,prev,n,a,dp);
        
        return dp[curr][prev+1]= max(inc, exc);
        
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       return solve(0,-1,n,a,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends