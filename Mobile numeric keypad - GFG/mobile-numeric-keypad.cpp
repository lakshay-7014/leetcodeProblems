//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	 long long solve(int i,int j, int row,int col,vector<vector<int>> &grid,int n, vector<vector<vector<long long>>> &dp){
         if(i<0 ||i>=row || j<0 || j>=col || grid[i][j]==-1){
            return 0;
        }       
        if(n==0){
            return 1;
        }
        if(dp[i][j][n]!=-1){
            return dp[i][j][n];
        }
      long long ans= solve(i,j-1,row,col,grid,n-1,dp);
       ans+= solve(i-1,j,row,col,grid,n-1,dp);
       ans+=solve(i,j+1,row,col,grid,n-1,dp);
       ans+=solve(i+1,j,row,col,grid,n-1,dp);
       ans+=solve(i,j,row,col,grid,n-1,dp);
      
       
       return dp[i][j][n]=ans;
    }
	long long getCount(int n)
	{
		// Your code goes here
		  int cnt=0;
        vector<vector<int>> grid
        {
          {1, 2, 3},
          {4, 5, 6},
          {7, 8, 9},
          {-1,0,-1}
        };
        vector<vector<vector<long long>>> dp(5,vector<vector<long long>>(4,vector<long long>(26,-1)));
        int row=4;
        int col=3;
        long long ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=-1){
                  ans = ans + solve(i,j,row,col,grid,n-1,dp);
                }
            }
        }
        return ans;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends