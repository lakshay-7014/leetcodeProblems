//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(unordered_map<int,bool> &vis,int &cnt,unordered_map<int,vector<int>> &adj,int node){
        vis[node]=true;
        
        for(auto j : adj[node]){
            if(vis[j]==false){
                dfs(vis,cnt,adj,j);
            }
        }
    }
    int numProvinces(vector<vector<int>> v, int v1) {
        // code here
        unordered_map<int,vector<int>> adj;
        int r= v.size();
        int c= v[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(v[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        unordered_map<int,bool> vis;
        int cnt=0;
        for(int i=0;i<v1;i++){
            if(vis[i]==false){
                dfs(vis,cnt,adj,i);
                 cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends