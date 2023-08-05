//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int solve(int coins[],int amount,int n,vector<int> &dp){
	    if(amount==0){
	        return 0;
	    }
	    if(amount<0){
	        return 1e9;
	    }
	    if(dp[amount]!=-1){
	        return dp[amount];
	    }
	    int res=1e9;
	    for(int i=0;i<n;i++){
	        int ans=1+solve(coins,amount-coins[i],n,dp);
	        res=min(res,ans);
	    }
	    return dp[amount]=res;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<int> dp(V+1,-1);
	    int ans= solve(coins,V,M,dp);
	    if(ans==1e9){
	        return -1;
	    }
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends