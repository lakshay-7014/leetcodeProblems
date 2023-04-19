//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>& height,int n , int i, vector<int> &dp){
        if(i==n-1){
            return 0;
        }
        if(i>=n){
            return INT_MAX;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int a=INT_MAX;
        int b=INT_MAX;
        if(i+1<n){
             a = solve(height,n,i+1,dp);
            if(a!=INT_MAX){
                a += abs(height[i+1]-height[i]);
            }
        }
        if(i+2<n){
            b=solve(height,n,i+2,dp);
            if(b!=INT_MAX){
                b+=abs(height[i+2]-height[i]);
            }
        }
        
        dp[i]= min(a,b);
        return dp[i];
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        
        // Code here
        vector<int> dp(n+1,-1);
        return solve(height,n,0,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends