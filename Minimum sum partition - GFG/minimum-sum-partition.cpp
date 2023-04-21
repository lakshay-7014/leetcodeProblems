//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
   int ans=INT_MAX;
    int solve(int i, int curr, int sum , int arr[],int n, vector<vector<int>> &dp){
        
        if(ans>abs(curr-sum)){
            ans=abs(curr-sum);
        }
        if(i>=n){
            return ans;
        }
        
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        
        
        int inc= solve(i+1,curr+arr[i],sum-arr[i],arr,n,dp);
        int exc= solve(i+1,curr,sum,arr,n,dp);
        
        return dp[i][curr]= min(inc,exc);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	      sum+=arr[i];
	    }
	    
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    
	   return  solve(0,0,sum,arr,n,dp);
	   // return ans;
	    
	}
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends