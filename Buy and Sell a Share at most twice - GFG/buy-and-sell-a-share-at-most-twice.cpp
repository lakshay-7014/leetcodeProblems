//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int solve(int i , int flag,int limit,vector<int>&price,int n, vector<vector<vector<int>>> &dp){
    if(i>=n){
        return 0;
    }
    if(limit==0){
        return 0;
    }
    
    
    if(dp[i][flag][limit]!=-1){
        return dp[i][flag][limit];
    }
    
    if(flag==1){
        int ans1= -price[i]+solve(i+1,0,limit,price,n,dp);
        int ans2= solve(i+1,1,limit,price,n,dp);
        return dp[i][flag][limit]=max(ans1,ans2);
    }
    else{
         int ans3= price[i]+solve(i+1,1,limit-1,price,n,dp);
         int ans4= solve(i+1,0,limit,price,n,dp);
         return dp[i][flag][limit]=max(ans3,ans4);
    }
    
}
int maxProfit(vector<int>&price){
    
    //Write your code here..
    int n =price.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,(vector<int>(3,-1))));
    ///vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<long long>(3,-1)));
    return solve(0,1,2,price,n,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends