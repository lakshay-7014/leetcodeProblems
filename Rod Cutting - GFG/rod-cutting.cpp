//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i , int limit , int price[],int n, vector<vector<int>> &dp){
        if(limit<0){
            return INT_MIN;
        }
        if(i>=n){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        
        if(dp[i][limit]!=-1){
            return dp[i][limit];
        }
        
        int inc= price[i]+ solve(i,limit-i-1,price,n,dp);
        int exc= solve(i+1,limit,price,n,dp);
        
        return dp[i][limit]=max(inc,exc);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends