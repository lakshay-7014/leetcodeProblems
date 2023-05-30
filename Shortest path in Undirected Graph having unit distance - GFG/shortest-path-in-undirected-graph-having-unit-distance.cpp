//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> parent;
        unordered_map<int,bool> vis;
        
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        q.push(src);
        vis[src]=true;
        while(q.size()!=0){
            int fr= q.front();
            q.pop();
            for(auto j : adj[fr]){
                if(vis[j]==false){
                    q.push(j);
                    parent[j]=fr;
                    vis[j]=true;
                }
            }
        }
        vector<int> ans(N,0);
        ans[src]=0;
        for(int i=0;i<N;i++){
            int val=i;
            int cnt=0;
            while(i!=src && parent[val]!=src && vis[i]==true){
                val=parent[val];
                cnt++;
                
            }
            if(i!=src && vis[i]==true){
                ans[i]=cnt+1;
            }
            else if(vis[i]==false){
                ans[i]=-1;
            }
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends