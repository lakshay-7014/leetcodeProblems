//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
   
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int r=grid.size();
        int c= grid[0].size();
        int tim=0;
        bool flag=false;
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        while(q.size()!=0){
            pair<int,int> p= q.front();
            q.pop();
            if(p.first==-1){
                if(q.size()==0){
                    break;
                }
                else{
                    tim++;
                    q.push({-1,-1});
                }
            }
            else{
                int i= p.first;
                int j=p.second;
                if(i-1>=0 && grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                }
                if(j-1>=0 &&  grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                }
                if(i+1<r &&  grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                }
                if(j+1<c &&  grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tim;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends