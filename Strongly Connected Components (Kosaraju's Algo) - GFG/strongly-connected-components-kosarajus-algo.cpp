//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node, unordered_map<int,bool> &vis,vector<vector<int>>& adj,stack<int> &s){
	    vis[node]=true;
	    for(auto j : adj[node]){
	        if(vis[j]==false){
	            dfs(j,vis,adj,s);
	        }
	    }
	    s.push(node);
	}
	void dfs1(int node,unordered_map<int,bool> &vis, unordered_map<int,vector<int> > &adj){
	    vis[node]=true;
	    for(auto j : adj[node]){
	        if(vis[j]==false){
	            dfs1(j,vis,adj);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
      
        stack<int> s;
        unordered_map<int,bool> vis;
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                dfs(i,vis,adj,s);
            }
        }
        vis.clear();
        unordered_map<int,vector<int> > tr;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                tr[adj[i][j]].push_back(i);
            }
        }
        int ans=0;
        while(s.size()!=0){
            int top= s.top();
            s.pop();
            if(vis[top]==false){
                ans++;
                dfs1(top,vis,tr);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends