//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom

    int minimumCostPath(vector<vector<int>>& grid) 
    {
         priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >  pq;
        int r= grid.size();
        int c= grid[0].size();
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        int i =0;
        int j = 0;
        pq.push({grid[i][j],{i,j}});
        dist[i][j]=grid[i][j];
        while(pq.size()!=0){
            pair<int,pair<int,int>> top= pq.top();
            pq.pop();
            int dis= top.first;
            int x=top.second.first;
            int y= top.second.second;
            if(x-1>=0 && dis+grid[x-1][y]<dist[x-1][y]){
                dist[x-1][y]=dis+grid[x-1][y];
                pq.push({dist[x-1][y],{x-1,y}});
            }
            if(y-1>=0&&  dis+grid[x][y-1]<dist[x][y-1]){
                dist[x][y-1]=dis+grid[x][y-1];
                pq.push({dist[x][y-1],{x,y-1}});
            }
            if(x+1<r&&  dis+grid[x+1][y]<dist[x+1][y]){
                dist[x+1][y]= dis+grid[x+1][y];
                pq.push({dist[x+1][y],{x+1,y}});
            }
            if(y+1<c&&  dis+grid[x][y+1]<dist[x][y+1]){
                dist[x][y+1]=dis+grid[x][y+1];
                pq.push({dist[x][y+1],{x,y+1}});
            }
        }
        int x1=r-1;
        int y1=c-1;
        if(dist[x1][y1]!=INT_MAX){
            return dist[x1][y1];
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends