//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    # define mod 1000000007
     int solve(int i , int j,int a,int b , vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(i==a-1 && j==b-1){
            if(grid[i][j]==0){
                return 1;
            }
            return 0;
        }
        if(i>=a){
            return 0;
        }
        if(j>=b){
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int down = solve(i+1,j,a,b,dp,grid);
        int right= solve(i,j+1,a,b,dp,grid);
        return dp[i][j]= (down%mod+right%mod)%mod;
        
        
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,dp,grid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends