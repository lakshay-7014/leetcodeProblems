//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long ans=-1;
 void solve(int parent, vector<int> &par,vector<int> & temp,unordered_map<int,vector<int>> &adj,vector<int> &visited,vector<bool> &dfsVisit,int node){
    visited[node]=1;
    dfsVisit[node]=true;
    temp.push_back(node);
    par[node]=parent;
    for(auto i : adj[node]){
        if(visited[i]==0){
            solve(node,par,temp,adj,visited,dfsVisit,i);
        }
        else if(dfsVisit[i]==true && visited[i]!=2){
            long long sum=i;
            while(node!=i){
                sum+=node;
                node=par[node];
            }
            ans=max(ans,sum);
        }
    }
    dfsVisit[node]=false;
  //  return false;
}

  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<N;i++){
        if(Edge[i]!=-1){
          adj[i].push_back(Edge[i]);
          //adj[Edge[i]].push_back(i);
        }
    }
     vector<int> vis(N,0);
    vector<bool> dfsVis(N,0);
    vector<int> parent(N,-1);
  for(int i=0;i<N;i++){
        if(vis[i]==0){
            vector<int> temp;
            solve(-1,parent,temp,adj,vis,dfsVis,i);
            for(auto j: temp){
                vis[j]=2;
            }
        }
  }
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends