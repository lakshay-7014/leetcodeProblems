//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int node,unordered_map<int,bool> &vis,vector<int> adj[]){
        unordered_map<int,int> parent;
        parent[node]=-1;
        queue<int> q;
        q.push(node);
        vis[node]=true;
        
        while(q.size()!=0){
            int fr= q.front();
            q.pop();
            
            for(auto j : adj[fr]){
                if(vis[j]==true && j!=parent[fr]){
                    return true;
                }
                else if(vis[j]==false){
                    q.push(j);
                    vis[j]=true;
                    parent[j]=fr;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool> vis;
        
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                bool ans= solve(i,vis,adj);
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
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends