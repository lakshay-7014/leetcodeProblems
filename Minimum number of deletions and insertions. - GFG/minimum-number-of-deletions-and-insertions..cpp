//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int i , int j , string &str1,string &str2, vector<vector<int>> &dp){
        if(i>=str1.size()){
            return str2.size()-j;
        }
        if(j>=str2.size()){
            return str1.size()-i;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(str1[i]==str2[j]){
            return solve(i+1,j+1,str1,str2,dp);
        }
        int ins= 1+ solve(i,j+1,str1,str2,dp);
        int del= 1+ solve(i+1,j,str1,str2,dp);
        return dp[i][j]=min(ins,del);
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	     int n= str1.size();
	     int m = str2.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
      return solve(0,0,str1,str2,dp);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends