//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	#define mod 1000000007
	int solve(int index,int arr[],int target,int n, vector<vector<int>> &dp){
        if(index>=n){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(target==0){
            return 1 + solve(index+1,arr,target-arr[index],n,dp);
        }
        if(target<0){
            return 0;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
    
           int inc= solve(index+1,arr,target-arr[index],n,dp);
           inc=inc%mod;
    
           int exc = solve(index+1,arr,target,n,dp);
           exc=exc%mod;
           dp[index][target]=(inc+exc)%mod;
           return dp[index][target];
    }
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,arr,sum,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends