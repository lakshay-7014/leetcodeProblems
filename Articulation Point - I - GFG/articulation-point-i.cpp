//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,int &timer,vector<int> &disc,vector<int> &low,int parent,unordered_map<int,bool> &vis, vector<int> adj[],set<int> &ans){
        vis[node]=true;
        disc[node]=low[node]=timer++;
        
        int child=0;
        for(auto j: adj[node]){
            if(j==parent){
                continue;
            }
            if(vis[j]==false){
                dfs(j,timer,disc,low,node,vis,adj,ans);
                low[node]=min(low[node],low[j]);
                if(low[j]>=disc[node] && parent!=-1){
                    ans.insert(node);
                }
                child++;
            }
            else{
                low[node]=min(low[node],disc[j]);
            }
        }
        if(parent==-1 && child>1){
            ans.insert(node);
        }

}
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int timer=0;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        set<int> ans;
        int parent=-1;
        unordered_map<int,bool> vis;
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                dfs(i,timer,disc,low,parent,vis,adj,ans);
            }
        }
        if(ans.size()==0){
            return {-1};
        }
        vector<int> res;
        for(auto i : ans){
            res.push_back(i);
            
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends