//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	static bool cmp(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> & b){
	    return a.second.second<b.second.second;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findParent(int node,vector<int> &parent){
	    if(parent[node]==node){
	        return node;
	    }
	    return parent[node]=findParent(parent[node],parent);
	}
	void unionSet(int u , int v , vector<int> & parent , vector<int> & rank){
	    if(rank[u]<rank[v]){
	        parent[u]=v;
	        //rank[v]++;
	    }
	    else if(rank[v]<rank[u]){
	        parent[v]=u;
	        //rank[u]++;
	    }
	    else{
	        parent[v]=u;
	        rank[u]++;
	    }
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
    
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto j : adj[i]){
                edges.push_back(  {i,{j[0], j[1]} } );
            }
            
        }
        vector<int> parent(V);
        vector<int> rank(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        int ans=0;
        sort(edges.begin(),edges.end(),cmp);
        for(int i=0;i<edges.size();i++){
            pair<int,pair<int,int>> p = edges[i];
            int u = p.first;
            int v= p.second.first;
            int wt=p.second.second;
            u= findParent(u,parent);
            v= findParent(v,parent);
            if(u!=v){
                unionSet(u,v,parent,rank);
                ans+=wt;
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