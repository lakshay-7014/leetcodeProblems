//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool solve(int i ,int n ,int sum, int nums[], vector<vector<int>> &dp){
        if(sum==0){
            return 1;
        }
        if(sum<0 || i>=n){
            return false;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        bool inc = solve(i+1,n,sum-nums[i],nums,dp);
        bool exc= solve(i+1,n,sum,nums,dp);

        dp[i][sum]= inc||exc;

        return dp[i][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
         int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }

        if(sum%2!=0){
            return false;
        }
       
        sum= sum/2;
        vector<vector<int>> dp(N,vector<int> (sum+1,-1));

        return solve(0,N,sum,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends