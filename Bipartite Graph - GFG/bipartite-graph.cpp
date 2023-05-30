//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int node ,vector<int> &vis,vector<int>adj[]){
        
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(q.size()!=0){
            int fr= q.front();
            q.pop();
            for(auto j : adj[fr]){
                if(vis[j]==-1){
                    q.push(j);
                    if(vis[fr]==1){
                        vis[j]=2;
                        
                    }
                    else{
                        vis[j]=1;
                    }
                }
                else{
                    if(vis[fr]==1 && vis[j]==1){
                        return false;
                    }
                    if(vis[fr]==2 && vis[j]==2){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	          bool ans = bfs(i,vis,adj);
	          if(ans==false){
	              return false;
	          }
	        }
	    }
	   
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends