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
         vector<int> in(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j : adj[i]){
	            in[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(in[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    
	    while(q.size()!=0){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto j : adj[node]){
	            in[j]--;
	            if(in[j]==0){
	                q.push(j);
	            }
	        }
	    }
	    if(ans.size()==V){
	        return false;
	    }
	    return true;
        
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