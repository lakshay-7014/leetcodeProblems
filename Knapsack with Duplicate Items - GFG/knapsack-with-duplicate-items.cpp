//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve( int wt[], int val[],int i, int n,int capacity,vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        
        if(capacity<0){
            return 0;
        }
        if(dp[i][capacity]!=-1){
        return dp[i][capacity];
    }  
        int inc=0;
        if(wt[i]<=capacity){
            inc= val[i]+solve(wt,val,i,n,capacity-wt[i],dp);
        }
        int exc=0+solve(wt,val,i+1,n,capacity,dp);
        
       dp[i][capacity]= max(inc,exc);
        return  dp[i][capacity];
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // Your code here
       vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
       return solve(wt,val,0,N,W,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends