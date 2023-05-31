//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node,int &timer,vector<int> &disc,vector<int> &low,int parent,unordered_map<int,bool> &vis, vector<int> adj[],int &ans,int c,int d){
        vis[node]=true;
        disc[node]=low[node]=timer++;
        for(auto j: adj[node]){
            if(j==parent){
                continue;
            }
            if(vis[j]==false){
                dfs(j,timer,disc,low,node,vis,adj,ans,c,d);
                low[node]=min(low[node],low[j]);
                if(low[j]>disc[node] &&((j==c && node==d) || (j==d && node==c))){
                    ans=1;
                }
            }
            else{
                low[node]=min(low[node],disc[j]);
            }
        }

}
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        int timer=0;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        int ans=0;
        int parent=-1;
        unordered_map<int,bool> vis;
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                dfs(i,timer,disc,low,parent,vis,adj,ans,c,d);
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
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends