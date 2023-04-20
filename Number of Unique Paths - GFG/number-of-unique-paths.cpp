//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int solve(int i , int j,int a,int b , vector<vector<int>> &dp){
        if(i==a-1 && j==b-1){
            return 1;
        }
        if(i>=a){
            return 0;
        }
        if(j>=b){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int down = solve(i+1,j,a,b,dp);
        int right= solve(i,j+1,a,b,dp);
        return dp[i][j]= down+right;
        
        
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        
        vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        return solve(0,0,a,b,dp);
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends