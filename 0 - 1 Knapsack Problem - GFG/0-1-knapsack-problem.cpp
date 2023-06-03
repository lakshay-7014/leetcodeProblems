//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int i ,int capacity,int wt[],int val[],int n,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][capacity]!=-1){
            return dp[i][capacity];
        }
        int inc =0;
        if(wt[i]<=capacity){
            inc= val[i]+solve(i+1,capacity-wt[i],wt,val,n,dp);
        }
        int exc= 0+ solve(i+1,capacity,wt,val,n,dp);
        return dp[i][capacity]= max(inc,exc);
    }
    
    //tabulation
    
    int solve2(int w,int wt[],int val[],int n){
         vector<vector<int>>dp(n+1,vector<int>(w+1,0));
         for(int i=1;i<=n;i++){
             for(int j=1;j<=w;j++){
                 if(wt[i-1]<=j){
                     dp[i][j]=max(val[i-1]+ dp[i-1][j-wt[i-1]],dp[i-1][j]);
                     
                 }
                 else{
                     dp[i][j]=dp[i-1][j];
                 }
             }
         }
         return dp[n][w];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve2(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends