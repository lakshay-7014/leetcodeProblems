//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >  pq;
        int r= grid.size();
        int c= grid[0].size();
        
        vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
        int i =source.first;
        int j = source.second;
        pq.push({0,{i,j}});
        dist[i][j]=0;
        while(pq.size()!=0){
            pair<int,pair<int,int>> top= pq.top();
            pq.pop();
            int dis= top.first;
            int x=top.second.first;
            int y= top.second.second;
            if(x-1>=0 && grid[x-1][y]==1 && dis+1<dist[x-1][y]){
                dist[x-1][y]=dis+1;
                pq.push({dist[x-1][y],{x-1,y}});
            }
            if(y-1>=0&& grid[x][y-1]==1 && dis+1<dist[x][y-1]){
                dist[x][y-1]=dis+1;
                pq.push({dist[x][y-1],{x,y-1}});
            }
            if(x+1<r&& grid[x+1][y]==1 && dis+1<dist[x+1][y]){
                dist[x+1][y]=dis+1;
                pq.push({dist[x+1][y],{x+1,y}});
            }
            if(y+1<c&& grid[x][y+1]==1 && dis+1<dist[x][y+1]){
                dist[x][y+1]=dis+1;
                pq.push({dist[x][y+1],{x,y+1}});
            }
            
        }
        int x1=destination.first;
        int y1=destination.second;
        if(dist[x1][y1]!=INT_MAX){
            return dist[x1][y1];
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends