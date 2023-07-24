//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int n) {
        // code here
        vector<int> ans;
         if(n==0 || n==1){
            return {};
        }
        vector<bool> vis(n+1,true);
        vis[0]=false;
        vis[1]=false;
        for(int i=2;i<=n;i++){
            if(vis[i]==true){
                int c=2;
                int j= c*i;
                while(j<=n){
                    vis[j]=false;
                    c++;
                    j=c*i;
                }
            }
        }
        
        for(int i= M;i<=n;i++){
            if(vis[i]==true){
                ans.push_back(i);
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
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends