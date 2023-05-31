//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> vis(V,false);
        vector<int> dist(V,INT_MAX);
        vector<int> parent(V,-1);
        parent[0]=-1;
        dist[0]=0;
        
        for(int i=0;i<V;i++){
            int mini=INT_MAX;
            int u;
            for(int j=0;j<V;j++){
                if(vis[j]==false && dist[j]<mini){
                    mini=dist[j];
                    u=j;  
                }
            }
            vis[u]=true;
            for(auto j : adj[u]){
                int v=j[0];
                int wt=j[1];
                if(vis[v]==false && wt<dist[v]){
                    parent[v]=u;
                    dist[v]=wt;
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            if(parent[i]!=-1){
                ans+=dist[i];
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends