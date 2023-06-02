//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    long long int solve(int index,int coins[],int n,int sum,vector<vector<long long int>> &dp){
        if(index>=n){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(sum<0){
            return 0;
        }
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        long long int inc=solve(index,coins,n,sum-coins[index],dp);
        long long int exc= solve(index+1,coins,n,sum,dp);
        return dp[index][sum]= inc+exc;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,-1));
        return solve(0,coins,N,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends