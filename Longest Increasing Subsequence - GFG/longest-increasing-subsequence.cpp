//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
   int solve(int n ,int a[],int curr,int prev,vector<vector<int>> &dp){
        if(curr==n){
            return 0;
        }
        if( dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int inc=0;
        if(prev==-1 || a[curr]> a[prev]){
            inc=1+ solve(n,a,curr+1,curr,dp);
        }
        int exc= solve(n,a,curr+1,prev,dp);
        dp[curr][prev+1]=max(inc,exc);
        return dp[curr][prev+1];
    }
    
    
    int solve2(int n, int a[]){
        if(n==0){
            return 0;
        }
        vector<int> temp;
        temp.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]> temp.back()){
                temp.push_back(a[i]);
            }
            else{
                int index= lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
                temp[index]=a[i];
            }
        }
        return temp.size();
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
      // return solve(n,a,0,-1,dp);
      return solve2(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends