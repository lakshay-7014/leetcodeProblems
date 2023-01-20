//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve( int wt[], int val[],int i, int n,int capacity,vector<vector<int>> &dp){
        if(i==n-1){
            if(wt[i]<=capacity){
                return val[i];
            }
            return 0;
        }
        if(dp[i][capacity]!=-1){
        return dp[i][capacity];
    }  
        int inc=0;
        if(wt[i]<=capacity){
            inc= val[i]+solve(wt,val,i+1,n,capacity-wt[i],dp);
        }
        int exc=0+solve(wt,val,i+1,n,capacity,dp);
        
       dp[i][capacity]= max(inc,exc);
        return  dp[i][capacity];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return solve(wt,val,0,n,W,dp);
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