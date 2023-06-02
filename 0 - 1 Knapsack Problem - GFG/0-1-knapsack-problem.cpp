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
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve(0,W,wt,val,n,dp);
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