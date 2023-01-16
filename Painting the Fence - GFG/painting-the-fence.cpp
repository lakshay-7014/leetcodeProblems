//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
    public:
    #define MOD 1000000007
    
     int mul(int a , int b){
          return ((a%1000000007 * 1LL * b%1000000007)%1000000007);
     }

    int add(int a , int b){
          return ((a%1000000007 + b%1000000007)%1000000007);
     }

    int solve(int n, int k,vector<int> &dp){
    
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k,k-1));
    }
    
    
    if(dp[n]!=-1){
        return dp[n];
    }
     dp[n] = add(mul(solve(n-2,k,dp),k-1),mul(solve(n-1,k,dp),k-1));
    
    return dp[n];
    
  
}
 int solve2(int n, int k){
    vector<long long > dp(n+1,0);
    dp[1]=k;
    dp[2]= add(k, mul(k,k-1));
   
    
    
    for(int i=3;i<=n;i++){
        dp[i]= add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    
    return dp[n];
    
  
}
    long long countWays(int n, int k){
        // code here
        
        return solve2(n,k);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends