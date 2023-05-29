//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int r=grid.size();
	    int c=grid[0].size();
	    vector<vector<int>> ans(r,vector<int>(c,0));
	    vector<vector<bool>> vis(r,vector<bool>(c,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=true;
	            }
	        }
	    }
	    
	    while(q.size()!=0){
	        pair<pair<int,int>,int> p= q.front();
	        q.pop();
	        int x= p.first.first;
	        int y=p.first.second;
	        
	        int st=p.second;
	        ans[x][y]=st;
	        if(x-1>=0 && vis[x-1][y]==false){
	            q.push({{x-1,y},st+1});
	            vis[x-1][y]=true;
	        }
	        if(x+1<r && vis[x+1][y]==false){
	             q.push({{x+1,y},st+1});
	             vis[x+1][y]=true;
	        }
	        if(y-1>=0 && vis[x][y-1]==false){
	             q.push({{x,y-1},st+1});
	             vis[x][y-1]=true;
	        }
	        if(y+1<c && vis[x][y+1]==false){
	             q.push({{x,y+1},st+1});
	             vis[x][y+1]=true;
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends