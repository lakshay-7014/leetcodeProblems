//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int solve(int i, int j , string &s1, string &s2,int m , int n, vector<vector<int>> &dp){
        if(i>=m || j>=n){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s1[i]==s2[j]){
            return 1+ solve(i+1,j+1,s1,s2,m,n,dp);
        }
        
        int ans = max(solve(i+1,j,s1,s2,m,n,dp),solve(i,j+1,s1,s2,m,n,dp));
        
        return dp[i][j]=ans;
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int len= solve(0,0,X,Y,m,n,dp);
         int a=  X.size()-len;
         int b=Y.size()-len;
         len=len+a+b;
        return len;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends