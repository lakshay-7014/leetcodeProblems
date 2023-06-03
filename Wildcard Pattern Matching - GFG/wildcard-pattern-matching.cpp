//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/


    int solve(int i , int j,string &s,string &p,int n,int m,vector<vector<int>> &dp){
        if(i>=n && j>=m){
            return true;
        }
        if(i<n && j>=m){
            return false;
        }
        
        if(i>=n && j<m){
            for(int k=j;k<m;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=solve(i+1,j+1,s,p,n,m,dp);
        }
        else if(p[j]=='*'){
            
            return dp[i][j]=solve(i,j+1,s,p,n,m,dp) || solve(i+1,j,s,p,n,m,dp);
        }
        return false;
        
    }
    int wildCard(string pattern,string str)
    {
        int n = str.size();
        int m = pattern.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,str,pattern,n,m,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends