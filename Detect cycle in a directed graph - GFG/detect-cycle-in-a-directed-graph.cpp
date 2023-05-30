//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<bool> &vis,vector<bool> &dfsVis,vector<int> adj[]){
        vis[node]=true;
        dfsVis[node]=true;
        for(auto j: adj[node]){
            if(vis[j]==false){
                bool ans= dfs(j,vis,dfsVis,adj);
                if(ans==true){
                    return true;
                }
            }
            else if(dfsVis[j]==true){
                return true;
            }
        }
        dfsVis[node]=false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,0);
        vector<bool> dfsVis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                bool ans= dfs(i,vis,dfsVis,adj);
                if(ans==true){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends