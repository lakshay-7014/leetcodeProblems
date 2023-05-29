//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i , int j , int n , int m ,vector<vector<int>> &mat){
        if(mat[i][j]==1){
            mat[i][j]=0;
            if(i-1>=0){
                dfs(i-1,j,n,m,mat);
            }
            if(j-1>=0){
                dfs(i,j-1,n,m,mat);
            }
            if(i+1<n){
                dfs(i+1,j,n,m,mat);
            }
            if(j+1<m){
                dfs(i,j+1,n,m,mat);
            }
        }
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0  || i==n-1 || j==m-1){
                    dfs(i,j,n,m,grid);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends