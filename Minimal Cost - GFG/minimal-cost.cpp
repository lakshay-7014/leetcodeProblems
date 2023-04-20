//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>& height, int n, int k,int i,vector<int> &dp){
        if(i==n-1){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        
        int ans=INT_MAX;
        
        for(int j=1;j<=k;j++){
            
            if(i+j<n){
                int temp= solve(height,n,k,i+j,dp);
                temp+=abs(height[i+j]-height[i]);
                ans=min(ans,temp);
            }
            else{
                break;
            }
        
        }
        return dp[i]= ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n+1,-1);
        return solve(height,n,k,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends