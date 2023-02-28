//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int solve(string &s1, string &s2,int i,int j, vector<vector<int>> &dp){
        if(i>=s1.size() || j>=s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;

        if(s1[i]==s2[j]){
           ans=  1+ solve(s1,s2,i+1,j+1,dp);
        }
        else{
            ans= max(solve(s1,s2,i,j+1,dp),solve(s1,s2,i+1,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
int minDeletions(string str, int n) { 
    //complete the function here 
   string rev=str;
   reverse(rev.begin(),rev.end());
   vector<vector<int>> dp(n,vector<int>(n,-1));
  int ans= solve(str,rev,0,0,dp);
    
    return n- ans;
}