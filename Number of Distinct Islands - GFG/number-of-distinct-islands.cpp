//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i , int j,vector<vector<int>>& grid, vector <pair<int,int > > &v,int lvl,int r,int c,int x,int y){
        grid[i][j]=0;
        //mp[lvl]++;
        v.push_back({x,y});
        if(i-1>=0 && grid[i-1][j]==1){
            dfs(i-1,j,grid,v,lvl+1,r,c,x-1,y);
        }
        if(j-1>=0 && grid[i][j-1]==1){
            dfs(i,j-1,grid,v,lvl+1,r,c,x,y-1);
        }
        if(i+1<r && grid[i+1][j]==1){
            dfs(i+1,j,grid,v,lvl+1,r,c,x+1,y);
        }
        if(j+1<c && grid[i][j+1]==1){
            dfs(i,j+1,grid,v,lvl+1,r,c,x,y+1);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int r= grid.size();
        int c= grid[0].size();
        set<vector <pair<int,int > > > s;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    vector <pair<int,int > > v;
                    dfs(i,j,grid,v,1,r,c,0,0);
                    s.insert(v);
                }
            }
        }
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends