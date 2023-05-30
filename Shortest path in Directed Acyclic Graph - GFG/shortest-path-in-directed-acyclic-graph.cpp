//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void solve(unordered_map<int,vector<pair<int,int>>> adj,unordered_map<int,bool> &visited, stack<int> &s, int node ){
         visited[node]=true;
         for(auto i : adj[node]){
             if(visited[i.first]==false){
                 solve(adj,visited,s,i.first);
             }
         }
         s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
         unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int x= edges[i][1];
            int y= edges[i][2];
            pair<int,int> p = make_pair(x,y);
            adj[a].push_back(p);
        }
        unordered_map<int,bool> visited;
        
        stack<int> s;
        for(int i=0;i<=N;i++){
            if(visited[i]==false){
                solve(adj,visited,s,i);
            }
        }
        
        vector<int> ans(N,INT_MAX);
        ans[0]=0;
        
        while(s.size()!=0){
            int node=s.top();
            s.pop();
            if(ans[node]!=INT_MAX){
                for(auto j : adj[node]){
                    if(ans[node]+j.second < ans[j.first]){
                        ans[j.first]=ans[node]+j.second;
                    }
                }
            }
            else{
                ans[node]=-1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends