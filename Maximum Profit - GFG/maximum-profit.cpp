//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i , int flag,int limit,int price[],int n, vector<vector<vector<int>>> &dp){
    if(i>=n){
        return 0;
    }
    if(limit==0){
        return 0;
    }
    
    
    if(dp[i][flag][limit]!=-1){
        return dp[i][flag][limit];
    }
    int ans1=0;
    int ans2=0;
    int ans3=0;
    int ans4=0;
    
    if(flag==1){
        ans1= -price[i]+solve(i+1,0,limit,price,n,dp);
         ans2= solve(i+1,1,limit,price,n,dp);
        return dp[i][flag][limit]=max(ans1,ans2);
    }
    else{
          ans3= price[i]+solve(i+1,1,limit-1,price,n,dp);
          ans4= solve(i+1,0,limit,price,n,dp);
         return dp[i][flag][limit]=max(ans3,ans4);
    }
    
}
    int maxProfit(int K, int N, int A[]) {
        // code here
         vector<vector<vector<int>>>dp(N,vector<vector<int>>(2,(vector<int>(K+1,-1))));
         return solve(0,1,K,A,N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends