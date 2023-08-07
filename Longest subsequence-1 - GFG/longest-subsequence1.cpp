//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int prev,int i,int n,int arr[], vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[prev+1][i]!=-1){
            
            return dp[prev+1][i];
        }
        
        int inc =0;
        if(prev==-1 || abs(arr[i]-arr[prev])==1){
            inc=1+solve(i,i+1,n,arr,dp);
        }
        int exc=0+solve(prev,i+1,n,arr,dp);
        
        return dp[prev+1][i]= max(inc,exc);
    }
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>> dp(N+2,vector<int>(N+1,-1));
        return solve(-1,0,N,A,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends