//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	 static bool cmp(pair<int, pair<int, int>> &a,pair<int, pair<int, int>> &b){
          return a.second.second<b.second.second;
    }
    int findParent(int node,vector<int> &parent){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node],parent);
}

void unionset(int u , int v,vector<int> &parent, vector<int> &rank){
  //  u=findParent(u,parent);
//    v= findParent(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
         vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                //cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"tt\n";
                edges.push_back({i, {it[0], it[1]}});
            }
        }
        sort(edges.begin(),edges.end(),cmp);
        vector<int> parent(V);
        vector<int> rank(V);
        for(int i=0;i<V;i++){
           rank[i]=0;
           parent[i]=i;
        }
        int ans=0;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v= edges[i].second.first;
        int wt= edges[i].second.second;
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(u!=v){
            unionset(u,  v,parent,rank);
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